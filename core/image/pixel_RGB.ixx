module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:RGB;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_weights;
import ks.core.image.pixel_traits;

export template <>
struct ks::core::image::pixel<rgb_t> {
    using traits = pixel_traits<rgb_t>;
    using value_t = traits::value_t;

    value_t r{traits::MIN};
    value_t g{traits::MIN};
    value_t b{traits::MIN};
    value_t a{traits::MAX};

    KS_CONSTEXPR pixel() = default;
    KS_CONSTEXPR explicit pixel(const value_t c_, const value_t a_ = traits::MAX) KS_NOEXCEPT
        : r{c_}, g{c_}, b{c_}, a{a_} {}
    KS_CONSTEXPR pixel(const value_t r_, const value_t g_, const value_t b_, const value_t a_ = traits::MAX) KS_NOEXCEPT
        : r{r_}, g{g_}, b{b_}, a{a_} {}

    KS_CONSTEXPR bool operator==(const pixel& other) KS_CONST KS_NOEXCEPT {
        return r == other.r && g == other.g && b == other.b && a == other.a;
    }

    KS_CONSTEXPR bool operator!=(const pixel& other) KS_CONST KS_NOEXCEPT {
        return !(*this == other);
    }

    KS_CONSTEXPR value_t Gray() KS_CONST KS_NOEXCEPT { return static_cast<value_t>(weights::GrayWeightR * r + weights::GrayWeightG * g + weights::GrayWeightB * b); }
};
