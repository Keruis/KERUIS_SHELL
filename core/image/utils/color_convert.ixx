module;

#include <stdint.h>
#include <cmath>
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

 auto hsv_to_rgb(float h, float s, float v) {
    float C = v * s;
    float X = C * (1.f - std::fabs(fmod(h / 60.f, 2.f) - 1.f));
    float m = v - C;

    float rf = 0.f, gf = 0.f, bf = 0.f;

    if (h < 60.f) {
        rf = C; gf = X; bf = 0.f;
    } else if (h < 120.f) {
        rf = X; gf = C; bf = 0.f;
    } else if (h < 180.f) {
        rf = 0.f; gf = C; bf = X;
    } else if (h < 240.f) {
        rf = 0.f; gf = X; bf = C;
    } else if (h < 300.f) {
        rf = X; gf = 0.f; bf = C;
    } else {
        rf = C; gf = 0.f; bf = X;
    }

    auto r = static_cast<uint8_t>((rf + m) * 255.f);
    auto g = static_cast<uint8_t>((gf + m) * 255.f);
    auto b = static_cast<uint8_t>((bf + m) * 255.f);

    return std::tuple{r, g, b};
}

}
