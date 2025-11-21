module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:HSV;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_traits;

export template <>
struct ks::core::image::pixel<hsv_t> {
    using traits = pixel_traits<hsv_t>;
    using value_t = traits::value_t;

    value_t h{traits::MIN};
    value_t s{traits::MIN};
    value_t v{traits::MIN};
    value_t a{traits::MIN};

    KS_CONSTEXPR pixel() = default;
    KS_CONSTEXPR explicit pixel(const value_t h_, const value_t s_, const value_t v_, const value_t a_ = traits::MAX)
        : h(h_), s(s_), v(v_), a(a_) {}

    bool operator==(const pixel& rhs) KS_CONST {
        return h == rhs.h && s == rhs.s && v == rhs.v;
    }

    bool operator!=(const pixel& rhs) KS_CONST {
        return !(*this == rhs);
    }
};
