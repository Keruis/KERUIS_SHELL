module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:HSL;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_traits;

template <>
struct ks::core::image::pixel<ks::core::image::color_model::hsl> {
    using traits = pixel_traits<hsl>;
    using value_t = traits::value_t;

    union {
        struct {
            value_t h;
            value_t s;
            value_t l;
        };
        struct {
            value_t c1;
            value_t c2;
            value_t c3;
        };
    };

    KS_CONSTEXPR pixel() : h{traits::range<1, false>()}, s{traits::range<2, false>()}, l{traits::range<3, false>()} {}
    KS_CONSTEXPR explicit pixel(const value_t h_, const value_t s_, const value_t l_) KS_NOEXCEPT
        : h(h_), s(s_), l(l_) {}

    KS_CONSTEXPR bool operator==(const pixel& rhs) KS_CONST KS_NOEXCEPT {
        return h == rhs.h && s == rhs.s && l == rhs.l;
    }

    KS_CONSTEXPR bool operator!=(const pixel& rhs) KS_CONST KS_NOEXCEPT {
        return !(*this == rhs);
    }
};
