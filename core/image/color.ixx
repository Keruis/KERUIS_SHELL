module;

#include "../utils/attributes.h"

export module ks.core.image.color;

import ks.core.image.color_space;
import ks.core.image.pixel_impl;
import ks.core.image.color_builder_impl;

export namespace ks::core::image {

template <color_model ColorSpace>
struct color {
    using pixel_t = pixel<ColorSpace>;
    using trait   = typename pixel_t::traits;
    using value_t = typename pixel_t::value_t;

    static KS_CONSTEXPR pixel_t White(value_t alpha = trait::MAX) {
        return color_builder<ColorSpace>::template make<color_tag::White>::build(alpha);
    }

    static KS_CONSTEXPR pixel_t Black(value_t alpha = trait::MAX) {
        return color_builder<ColorSpace>::template make<color_tag::Black>::build(alpha);
    }

    static KS_CONSTEXPR pixel_t Red(value_t alpha = trait::MAX) {
        return color_builder<ColorSpace>::template make<color_tag::Red>::build(alpha);
    }

    static KS_CONSTEXPR pixel_t Yellow(value_t alpha = trait::MAX) {
        return color_builder<ColorSpace>::template make<color_tag::Yellow>::build(alpha);
    }






    // static KS_CONSTEXPR pixel_RGB Black(const img_byte_t alpha = pixel_RGB::MAX) { return pixel_RGB(MIN, MIN, MIN, alpha); }
    // static KS_CONSTEXPR pixel_RGB Red(const img_byte_t alpha = pixel_RGB::MAX) { return pixel_RGB(MAX, MIN, MIN, alpha); }
    // static KS_CONSTEXPR pixel_RGB Green(const img_byte_t alpha =pixel_RGB::MAX) { return pixel_RGB(MIN, MAX, MIN, alpha); }
    // static KS_CONSTEXPR pixel_RGB Blue(const img_byte_t alpha = pixel_RGB::MAX) { return pixel_RGB(MIN, MIN, MAX, alpha); }
    // static KS_CONSTEXPR pixel_RGB Yellow(const img_byte_t alpha = pixel_RGB::MAX) { return pixel_RGB(MAX, MAX, MIN, alpha); }
    // static KS_CONSTEXPR pixel_RGB cyan(const img_byte_t alpha = MAX) { return pixel_RGB(MIN, MAX, MAX, alpha); }
    // static KS_CONSTEXPR pixel_RGB Magenta(const img_byte_t alpha = MAX) { return pixel_RGB(MAX, MIN, MAX, alpha); }
    // static KS_CONSTEXPR pixel_RGB Gray(const img_byte_t gray = DEFAULT_GRAY, const img_byte_t alpha = MAX) { return pixel_RGB(gray, gray, gray, alpha); }
    //
    // static KS_CONSTEXPR pixel_RGB Random() {
    //     return pixel_RGB(
    //         static_cast<img_byte_t>(rand() % (MAX + 1)),
    //         static_cast<img_byte_t>(rand() % (MAX + 1)),
    //         static_cast<img_byte_t>(rand() % (MAX + 1)),
    //         static_cast<img_byte_t>(rand() % (MAX + 1))
    //     );
    // }
    //
    // static KS_CONSTEXPR pixel_RGB ToRGB(const pixel_HSV& hsv, img_byte_t alpha = MAX)

};

}
