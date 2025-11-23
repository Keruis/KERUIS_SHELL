module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:HSVA;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_traits;

template <>
struct ks::core::image::pixel<ks::core::image::color_model::hsva> {
    using traits = pixel_traits<hsva>;
    using value_t = traits::value_t;

    value_t h{traits::MIN};
    value_t s{traits::MIN};
    value_t v{traits::MIN};
    value_t a{traits::MIN};

    KS_CONSTEXPR pixel() = default;
    KS_CONSTEXPR explicit pixel(const value_t h_, const value_t s_, const value_t v_, const value_t a_ = traits::MAX)
        : h(h_), s(s_), v(v_), a(a_) {}

    bool operator==(const pixel& rhs) KS_CONST {
        return h == rhs.h && s == rhs.s && v == rhs.v && a == rhs.a;
    }

    bool operator!=(const pixel& rhs) KS_CONST {
        return !(*this == rhs);
    }
};
