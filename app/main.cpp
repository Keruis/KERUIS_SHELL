#include <iostream>
#include <bits/ostream.tcc>
#include <chrono>
import ks.core.math.vec.vector2;


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

int main() {
    ks::core::math::vec::vector2<float> v1(1.0);
    v1.set_of(ks::core::math::vec::vector2<float>(5.0, 1.0), 3.0, 5.0, 6.0, 3.0);
    v1.add_of(2.0);
    v1.sub_of(1.0);
    std::cout << (v1 + v1).y << std::endl;
}
