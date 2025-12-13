module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:HSLA;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_traits;

template <>
struct ks::core::image::pixel<ks::core::image::color_model::hsla> {
    using traits = pixel_traits<hsla>;
    using value_t = traits::value_t;

    union {
        struct {
            value_t h;
            value_t s;
            value_t l;
            value_t a;
        };
        struct {
            value_t c1;
            value_t c2;
            value_t c3;
            value_t c4;
        };
    };

    KS_CONSTEXPR pixel() : h{traits::range<1, false>()}, s{traits::range<2, false>()}, l{traits::range<3, false>()}, a{traits::range<4, true>()} {}
    KS_CONSTEXPR explicit pixel(const value_t h_, const value_t s_, const value_t l_, const value_t a_ = traits::range<4, true>())
        : h(h_), s(s_), l(l_), a(a_) {}

    bool operator==(const pixel& rhs) KS_CONST {
        return h == rhs.h && s == rhs.s && l == rhs.l && a == rhs.a;
    }

    bool operator!=(const pixel& rhs) KS_CONST {
        return !(*this == rhs);
    }
};
