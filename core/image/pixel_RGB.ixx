module;

#include "../utils/attributes.h"

export module ks.core.image.pixel_impl:RGB;

import :pixel_base;
import ks.core.image.color_space;
import ks.core.image.pixel_weights;
import ks.core.image.pixel_traits;

template <>
struct ks::core::image::pixel<ks::core::image::color_model::rgb> {
    using traits = pixel_traits<rgb>;
    using value_t = traits::value_t;

    union {
        struct {
            value_t r;
            value_t g;
            value_t b;
        };
        struct {
            value_t c1;
            value_t c2;
            value_t c3;
        };
    };

    KS_CONSTEXPR pixel() : r{traits::range<1, false>()}, g{traits::range<2, false>()}, b{traits::range<3, false>()} {}
    KS_CONSTEXPR explicit pixel(const value_t c_) KS_NOEXCEPT
        : r{c_}, g{c_}, b{c_} {}
    KS_CONSTEXPR explicit pixel(const value_t r_, const value_t g_, const value_t b_) KS_NOEXCEPT
        : r{r_}, g{g_}, b{b_} {}

    KS_CONSTEXPR bool operator==(const pixel& other) KS_CONST KS_NOEXCEPT {
        return r == other.r && g == other.g && b == other.b;
    }

    KS_CONSTEXPR bool operator!=(const pixel& other) KS_CONST KS_NOEXCEPT {
        return !(*this == other);
    }

    KS_NODISCARD KS_CONSTEXPR value_t Gray() KS_CONST KS_NOEXCEPT { return static_cast<value_t>(weights::GrayWeightR * r + weights::GrayWeightG * g + weights::GrayWeightB * b); }
};
