module;

#include <chrono>
#include <atomic>
#include <mutex>
#include <thread>
#include <deque>
#include <utility>
#include <numeric>
#include <condition_variable>

#include "../../utils/constexpr_switch.h"

module ks.core.render.utils:frameRateCounter_impl;

import :frameRateCounter;

namespace ks::core::render::utils {

template<SmoothingMode Mode>
AsyncFrameRateCounter<Mode>::AsyncFrameRateCounter(std::size_t max_samples)
    : max_samples       (max_samples),
      running           (true),
      fps_value         (0.0f),
      min_fps           (std::numeric_limits<float>::max()),
      max_fps           (0.0f),
      avg_fps           (0.0f)
{
    worker              = std::thread(&AsyncFrameRateCounter::loop, this);
}

template<SmoothingMode Mode>
AsyncFrameRateCounter<Mode>::~AsyncFrameRateCounter() {
    running             = false;
    cv                  .notify_all             ();
    if (worker          .joinable               ())
        worker          .join                   ();
}

template<SmoothingMode Mode>
void AsyncFrameRateCounter<Mode>::notify_frame() {
    std::lock_guard                 lock(mtx);
    frame_times         .push_back              (clock::now());
    cv                  .notify_one             ();
}

template<SmoothingMode Mode>
float AsyncFrameRateCounter<Mode>::GetFPS() const {
    return fps_value    .load                   (std::memory_order_relaxed);
}

template<SmoothingMode Mode>
FrameStats AsyncFrameRateCounter<Mode>::GetStats() const {
    return {
            .fps        = fps_value         .load(),
            .min_fps    = min_fps           .load(),
            .max_fps    = max_fps           .load(),
            .avg_fps    = avg_fps           .load()
    };
}

template<SmoothingMode Mode>
void AsyncFrameRateCounter<Mode>::loop() {
    while (running) {
        std::unique_lock        lock(mtx);
        cv      .wait_for           (lock,
            std::chrono::milliseconds(100), [this] { return !frame_times.empty() || !running; }
        );

        auto now        = clock::now();

        while (!frame_times     .empty() &&
               std::chrono::duration_cast<std::chrono::seconds>(now - frame_times.front()).count() > 1) {
            frame_times         .pop_front();
        }

        if (frame_times.size() > 1) {
            float total_time = std::chrono::duration<float>(frame_times.back() - frame_times.front()).count();
            float new_fps = (frame_times.size() - 1) / total_time;
            fps_value.store(new_fps, std::memory_order_relaxed);

            float current_min = min_fps.load();
            float current_max = max_fps.load();

            if (new_fps < current_min) min_fps      .store      (new_fps);
            if (new_fps > current_max) max_fps      .store      (new_fps);
            __asm__ __volatile__("nop\n\t");
            core::utils::constexpr_switch<Mode>()
                    .template case_<SmoothingMode::Average>(
                            [&]{
                                avg_fps.store(
                                        std::accumulate(frame_times.begin() + 1, frame_times.end(), 0.0f,
                                                        [](float acc, const time_point&) {
                                                            return acc + 1.0f;
                                                        }
                                        ) / total_time
                                );
                            }
                    )
                    .template case_<SmoothingMode::EMA>(
                            [&]{
                                constexpr float     alpha           = 0.1f;
                                float               previous_avg    = avg_fps.load(std::memory_order_relaxed);
                                float               new_avg         = alpha * new_fps + (1.0f - alpha) * previous_avg;
                                avg_fps             .store(new_avg, std::memory_order_relaxed);
                            }
                    )
                    .default_(
                            []{
                                std::unreachable();
                            }
                    );
            __asm__ __volatile__("nop\n\t");
        } else {
            fps_value       .store(0.0f);
            avg_fps         .store(0.0f);
        }
    }
}

template class AsyncFrameRateCounter<SmoothingMode::Average>;
template class AsyncFrameRateCounter<SmoothingMode::EMA>;

}