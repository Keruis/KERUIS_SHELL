module;

#include <chrono>
#include <atomic>
#include <mutex>
#include <thread>
#include <deque>
#include <utility>
#include <condition_variable>

export module ks.core.render.utils:frameRateCounter;

export namespace ks::core::render::utils {

    enum class SmoothingMode {
        Average,
        EMA
    };

    struct FrameStats {
        float   fps;
        float   min_fps;
        float   max_fps;
        float   avg_fps;
    };

template<SmoothingMode Mode = SmoothingMode::Average>
class AsyncFrameRateCounter {
    public:
        using clock         =   std::chrono::steady_clock;
        using time_point    =   clock::time_point;

        explicit AsyncFrameRateCounter      (std::size_t max_samples = 100);
        ~AsyncFrameRateCounter              ();

        void        notify_frame            ();

        float       GetFPS                  ()      const;
        FrameStats  GetStats                ()      const;

    private:
        std::size_t             max_samples;
        std::deque<time_point>  frame_times;
        std::thread             worker;
        std::atomic<bool>       running;
        std::atomic<float>      fps_value;
        std::atomic<float>      min_fps;
        std::atomic<float>      max_fps;
        std::atomic<float>      avg_fps;

        mutable std::mutex      mtx;
        std::condition_variable cv;

        void         loop                   ();
    };

}