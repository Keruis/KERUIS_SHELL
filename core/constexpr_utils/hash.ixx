module;

#include <cstddef>
#include <stdint.h>

export module ks.core.constexpr_utils.hash;

export consteval uint32_t hash_constexpr(const char *str, std::size_t n) {
    uint32_t h = 2166136261u;
    for (std::size_t i = 0; i < n; i++) {
        h ^= static_cast<uint32_t>(str[i]);
        h *= 16777619u;
    }
    return h;
}