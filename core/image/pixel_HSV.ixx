module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:HSV;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_traits;

template <>
struct ks::core::image::pixel<ks::core::image::color_model::hsv> {
    using traits = pixel_traits<hsv>;
    using value_t = traits::value_t;

    value_t h{traits::MIN};
    value_t s{traits::MIN};
    value_t v{traits::MIN};

    KS_CONSTEXPR pixel() = default;
    KS_CONSTEXPR explicit pixel(const value_t h_, const value_t s_, const value_t v_) KS_NOEXCEPT
        : h(h_), s(s_), v(v_) {}

    KS_CONSTEXPR bool operator==(const pixel& rhs) KS_CONST KS_NOEXCEPT {
        return h == rhs.h && s == rhs.s && v == rhs.v;
    }

    KS_CONSTEXPR bool operator!=(const pixel& rhs) KS_CONST KS_NOEXCEPT {
        return !(*this == rhs);
    }
};
