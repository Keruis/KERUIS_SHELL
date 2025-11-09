module;

#include <chrono>
#include <thread>

export module ks.core.render.utils:frameLimiter;

export namespace ks::core::render::utils {

class FrameLimiter {
public:
    using clock     =   std::chrono::steady_clock;
    using duration  =   std::chrono::duration<double>;

    explicit FrameLimiter(double target_fps = 60.0, double sleep_precision_sec = 0.001);

    void beginFrame()                                                                  noexcept;
    void endFrame()                                                                  noexcept;

    void SetFPS(double fps)                                                        noexcept;
    double GetFPS() const                                                            noexcept;
    double GetDeltaTime() const                                                            noexcept;

private:
    double              frame_duration;
    double              sleep_precision;
    clock::time_point   current_frame_time;
    double              delta_time              = 0.0f;
    clock::time_point   last_frame_time;
};

}