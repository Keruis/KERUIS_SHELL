module;

#include <stdint.h>
#include <tuple>

export module ks.core.image.utils.color_convert;

export namespace ks::core::image::utils {

constexpr auto hex_to_rgb(uint32_t hex) {
    return std::tuple{
        static_cast<uint8_t>((hex >> 16) & 0xFF),
        static_cast<uint8_t>((hex >> 8) & 0xFF),
        static_cast<uint8_t>(hex & 0xFF)
    };
}

constexpr auto rgb_to_hsv(uint8_t r, uint8_t g, uint8_t b) {
    const float rf = r / 255.f;
    const float gf = g / 255.f;
    const float bf = b / 255.f;

    const float max = rf > gf ? (rf > bf ? rf : bf) : (gf > bf ? gf : bf);
    const float min = rf < gf ? (rf < bf ? rf : bf) : (gf < bf ? gf : bf);
    float h = 0.f, s = 0.f, v = max;

    float delta = max - min;

    if (max != 0.f) s = delta / max;

    if (delta != 0.f) {
        if (max == rf) h = (gf - bf) / delta;
        else if (max == gf) h = 2.f + (bf - rf) / delta;
        else h = 4.f + (rf - gf) / delta;

        h *= 60.f;
        if (h < 0.f) h += 360.f;
    }

    return std::tuple{h, s, v};
}

}
