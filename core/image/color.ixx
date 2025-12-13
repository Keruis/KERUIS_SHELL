module;

#include <cstdint>
#include <random>

#include "../utils/attributes.h"

export module ks.core.image.color;

import ks.core.image.color_space;
import ks.core.image.pixel_impl;
import ks.core.image.color_builder_impl;
import ks.core.constexpr_utils.string_literal;
import ks.core.image.utils.color_convert;

export namespace ks::core::image {

template <color_model ColorSpace>
struct color {
    using pixel_t = pixel<ColorSpace>;
    using trait   = typename pixel_t::traits;
    using value_t = typename pixel_t::value_t;

    template <string_literal STR>
    static KS_CONSTEXPR pixel_t build(value_t alpha = trait::template range<2, true>()) {
        return color_builder<ColorSpace>::template make<STR>::build(alpha);
    }

    static KS_CONSTEXPR pixel_t random() KS_NOEXCEPT {
        auto c1 = runtime_prog() * 1234567u;
        auto c2 = runtime_prog() * 9876543u;
        auto c3 = runtime_prog() * 5634697u;

        if constexpr (trait::CHANNELS == 3) {
            return pixel_t {
                trait::template normalize<1>(c1),
                trait::template normalize<2>(c2),
                trait::template normalize<3>(c3)
            };
        } else {
            return pixel_t {
                trait::template normalize<1>(c1),
                trait::template normalize<2>(c2),
                trait::template normalize<3>(c3),
                trait::template range<4, true>()
            };
        }
    }

    static KS_CONSTEXPR pixel_t mix(pixel_t a, pixel_t b, float t) KS_NOEXCEPT {
        if constexpr (trait::CHANNELS == 3) {
            return pixel_t {
                trait::template clamp<1>(trait::template lerp<1>(a.c1, b.c1, t)),
                trait::template clamp<2>(trait::template lerp<2>(a.c2, b.c2, t)),
                trait::template clamp<3>(trait::template lerp<3>(a.c3, b.c3, t)),
            };
        } else {
            return pixel_t {
                trait::template clamp<1>(trait::template lerp<1>(a.c1, b.c1, t)),
                trait::template clamp<2>(trait::template lerp<2>(a.c2, b.c2, t)),
                trait::template clamp<3>(trait::template lerp<3>(a.c3, b.c3, t)),
                trait::template clamp<4>((a.c4 + b.c4) / 2)
            };
        }
    }

    static KS_CONSTEXPR pixel_t clamp(pixel_t a) KS_NOEXCEPT {
        if constexpr (trait::CHANNELS == 3) {
            return pixel_t {
                trait::template clamp<1>(a.c1),
                trait::template clamp<2>(a.c2),
                trait::template clamp<3>(a.c3),
            };
        } else {
            return pixel_t {
                trait::template clamp<1>(a.c1),
                trait::template clamp<2>(a.c2),
                trait::template clamp<3>(a.c3),
                trait::template clamp<4>(a.c4)
            };
        }
    }

    template <color_model Other>
    static KS_CONSTEXPR pixel<Other> to(pixel_t p) KS_NOEXCEPT {
        auto convert_tuple = [&] {
            if constexpr ((ColorSpace == rgb && Other == hsv) || (ColorSpace == rgba && Other == hsva)) {
                return utils::rgb_to_hsv(p.c1, p.c2, p.c3);
            } else if constexpr ((ColorSpace == hsv && Other == rgb) || (ColorSpace == hsva && Other == rgba)) {
                return utils::hsv_to_rgb(p.c1, p.c2, p.c3);
            }
        }();

        if constexpr (get_color_space_size<Other>() == 3) {
            auto [c1, c2, c3] = convert_tuple;
            return pixel<Other>{c1, c2, c3};
        } else {
            auto [c1, c2, c3, c4] = convert_tuple;
            return pixel<Other>{c1, c2, c3, c4};
        }
    }

private:
    static uint32_t runtime_prog() {
#if defined(_MSC_VER)

        static std::random_device rd;
        static uint32_t seed = rd();
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        return seed;

#else

        // -------- GCC / Clang 路线：使用 rdtsc 汇编 --------
        uint32_t lo = 0, hi = 0;

        __asm__ __volatile__(
            "rdtsc"
            : "=a"(lo), "=d"(hi)
        );

        uint64_t tsc = (static_cast<uint64_t>(hi) << 32) | lo;

        // xorshift32 混合一下
        uint32_t x = static_cast<uint32_t>(tsc);
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        return x;

#endif
    }

};

}
