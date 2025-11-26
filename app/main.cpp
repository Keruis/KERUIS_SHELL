#include <iostream>
#include <bits/ostream.tcc>
#include <chrono>
#include <thread>
// import ks.core.math.vec.vector2;


// int main() {
//     using namespace ks::core::math::vec;
//
//     vector2<float> v;
//     vector2<float> u(5.0f, 6.0f);
//     std::array<float,2> arr{3.0f, 4.0f};
//
//     constexpr int N = 100'000'000;
//
//     float sink = 0.0f;
//
//     auto t1 = std::chrono::high_resolution_clock::now();
//     for(int i = 0; i < N; ++i) {
//         v.set_of(1.0f, 2.0f);
//         sink += v.x + v.y;
//     }
//     auto t2 = std::chrono::high_resolution_clock::now();
//     std::cout << "Scalar set: "
//               << std::chrono::duration<double>(t2-t1).count() << " s\n";
//
//     t1 = std::chrono::high_resolution_clock::now();
//     for(int i = 0; i < N; ++i) {
//         v.set_of(arr);
//         sink += v.x + v.y;
//     }
//     t2 = std::chrono::high_resolution_clock::now();
//     std::cout << "Array set: "
//               << std::chrono::duration<double>(t2-t1).count() << " s\n";
//
//     t1 = std::chrono::high_resolution_clock::now();
//     for(int i = 0; i < N; ++i) {
//         v.set_of(u);
//         sink += v.x + v.y;
//     }
//     t2 = std::chrono::high_resolution_clock::now();
//     std::cout << "vector2 set: "
//               << std::chrono::duration<double>(t2-t1).count() << " s\n";
//
//     std::cout << "sink=" << sink << "\n";
//
//     return 0;
// }

// int main() {
//     ks::core::math::vec::vector2<float> v1(1.0);
//     v1.set_of(ks::core::math::vec::vector2<float>(5.0, 1.0), 3.0, 5.0, 6.0, 3.0);
//     v1.add_of(2.0);
//     v1.sub_of(1.0);
//     std::cout << (v1 + v1).y << std::endl;
// }

// import ks.core.render.utils;
//
// int main() {
//     ks::core::render::utils::FrameLimiter limiter(60.0);
//     ks::core::render::utils::AsyncFrameRateCounter<> fps_counter;
//
//     constexpr int total_frames = 10;
//
//     for (int i = 0; i < total_frames; ++i) {
//         limiter.beginFrame();

//         fps_counter.notify_frame();
//         std::cout << "Frame " << i
//                   << ", DeltaTime: " << limiter.GetDeltaTime()
//                   << " s, FPS: " << fps_counter.GetFPS() << std::endl;
//
//         limiter.endFrame();
//     }
//
//     std::cout << "Test finished." << std::endl;
//     return 0;
// }
// #include <windows.h>
// import ks.core.render.input;
// import ks.platform;
//
// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//     switch (uMsg) {
//     case WM_DESTROY:
//         PostQuitMessage(0);
//         return 0;
//     }
//     return DefWindowProc(hwnd, uMsg, wParam, lParam);
// }
//
// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
//     WNDCLASS wc = {};
//     wc.lpfnWndProc = WindowProc;
//     wc.hInstance = hInstance;
//     wc.lpszClassName = "test";
//     RegisterClass(&wc);
//
//     HWND hwnd = CreateWindowEx(
//         0,
//         "test",
//         "eee",
//         WS_OVERLAPPEDWINDOW,
//         CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
//         nullptr, nullptr, hInstance, nullptr
//     );
//
//     if (!hwnd) return 0;
//
//     ShowWindow(hwnd, nCmdShow);
//
//     ks::platform::win32::WindowWin32 window;
//     window.Init(&hwnd);
//     ks::platform::win32::CursorControllerWin32 cursor;
//     cursor.Init(&hwnd);
//
//     ks::core::render::input::Mouse mouse(800, 600);
//     mouse.BindWindow(&window);
//     mouse.BindCursorController(&cursor);
//
//     MSG msg = {};
//     while (true) {
//         while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
//             if (msg.message == WM_QUIT) return 0;
//             TranslateMessage(&msg);
//             DispatchMessage(&msg);
//         }
//
//
//         mouse.frame();
//
//         std::cout << mouse.getPosition().x << ", " << mouse.getPosition().y << std::endl;
//
//         std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 约60FPS
//     }
//
//     return 0;
// }

// int main() {
//     ks::platform::win32::CursorControllerWin32 cursor;
//     ks::core::render::input::Mouse mose;
//     mose.BindCursorController(&cursor);
//     mose.setCursorMode(ks::core::render::input::CursorMode::Hidden);
//
//     std::this_thread::sleep_for(std::chrono::seconds(5));
//
//     mose.setCursorMode(ks::core::render::input::CursorMode::Normal);
// }

// import kstd.string;
//
// int main() {
//     ksstd::string a("ssss");
//     std::cout << a.c_str() << std::endl;
// }

import kstd.image;

int main() {

    ks::core::image::pixel<ks::core::image::rgba> a(30, 30, 30);
    std::cout << static_cast<int>(a.r) << std::endl;
    auto w = ks::core::image::color<ks::core::image::hsva>::Red();
    std::cout << static_cast<int>(w.h) << std::endl;
}