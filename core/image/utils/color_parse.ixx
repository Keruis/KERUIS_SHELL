module;

#include <string_view>
#include <array>

export module ks.core.image.utils.color_parse;

import kstd.constexpr_utils;

namespace ks::core::image::utils {

struct ColorData {
    std::string_view name;
    unsigned char r, g, b;
};

consteval size_t count_lines(std::string_view txt) {
    size_t count = 0;

    for (size_t i = 0; i < txt.size();) {
        while (i < txt.size() && constexpr_utils::is_space(txt[i])) i++;

        if (i < txt.size() && txt[i] == '{') {
            count++;
            while (i < txt.size() && txt[i] != '\n') i++;
        } else {
            while (i < txt.size() && txt[i] != '\n') i++;
        }

        if (i < txt.size() && txt[i] == '\n') i++;
    }
    return count;
}

template <size_t N>
consteval std::array<ColorData, N> parse_impl(std::string_view txt) {
    std::array<ColorData, N> arr{};
    size_t idx = 0;

    for (size_t i = 0; i < txt.size();) {

        while (i < txt.size() && constexpr_utils::is_space(txt[i])) i++;

        if (i < txt.size() && txt[i] == '{') {
            size_t start = i + 1;
            size_t end = txt.find('}', start);
            auto line = txt.substr(start, end - start);

            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            size_t p3 = line.find(',', p2 + 1);

            auto name = line.substr(0, p1);

            while (!name.empty() && constexpr_utils::is_space(name.front())) name.remove_prefix(1);
            while (!name.empty() && constexpr_utils::is_space(name.back()))  name.remove_suffix(1);

            auto to_int = [](std::string_view s) {
                int v = 0;
                for (char c : s) {
                    if (c >= '0' && c <= '9') {
                        v = v * 10 + (c - '0');
                    }
                }
                return v;
            };

            int r = to_int(line.substr(p1 + 1, p2 - p1 - 1));
            int g = to_int(line.substr(p2 + 1, p3 - p2 - 1));
            int b = to_int(line.substr(p3 + 1));

            arr[idx++] = { name, (unsigned char)r, (unsigned char)g, (unsigned char)b };

            i = end + 1;
        }

        while (i < txt.size() && txt[i] != '\n') i++;
        if (i < txt.size() && txt[i] == '\n') i++;
    }

    return arr;
}

template <std::string_view const& TXT>
struct ParseHelper {
    static constexpr size_t N = count_lines(TXT);
    static constexpr auto value = parse_impl<N>(TXT);
};

template <std::string_view const& TXT>
constexpr auto ParseColors() {
    return ParseHelper<TXT>::value;
}

constexpr std::string_view color_definitions =
#include "../color_definitions.inc"

export constexpr auto parsed_colors = ParseColors<color_definitions>();

export constexpr const ColorData* get_color(std::string_view name) {
    for (const auto& c : parsed_colors) {
        if (c.name == name) return &c;
    }
    return nullptr;
}

}