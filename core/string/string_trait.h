#ifndef STRING_TRAIT_H
#define STRING_TRAIT_H

#include "../utils/type_traits.h"
#include "character_type.h"

#include <cstring>
#include <cwchar>
#include <cstddef>

namespace ks::core::string::trait {

template <typename Ty_>
concept character_type = type::is_char_type_v<Ty_>;

template <character_type Ty_>
struct string_trait {
    using char_t          = Ty_;
    using const_char_t    = const Ty_;
    using pointer_t       = char_t*;
    using const_pointer_t = const_char_t*;

    constexpr static std::size_t type_size      = sizeof(char_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
        if (!str) return 0;
        while (str[n] != char_t(0)) ++n;
        return n;
    }

    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = src[i];
    }

    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    static constexpr int compare(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i) {
            if (lhs[i] < rhs[i]) return -1;
            if (lhs[i] > rhs[i]) return 1;
        }
        return 0;
    }

    static constexpr bool equal(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<char> {
    using char_t          = char;
    using const_char_t    = const char;
    using pointer_t       = char*;
    using const_pointer_t = const char*;

    constexpr static std::size_t type_size      = sizeof(char);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    static constexpr std::size_t length(const_pointer_t str) noexcept {
        return std::strlen(str);
            }

    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        std::memcpy(dest, src, count);
    }

    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        std::memset(dest, ch, count);
    }

    static constexpr int compare(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        return std::memcmp(lhs, rhs, count);
    }

    static constexpr bool equal(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        return std::memcmp(lhs, rhs, count) == 0;
    }
};

template <>
struct string_trait<wchar_t> {
    using char_t          = wchar_t;
    using const_char_t    = const wchar_t;
    using pointer_t       = wchar_t*;
    using const_pointer_t = const wchar_t*;

    constexpr static std::size_t type_size      = sizeof(wchar_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    static constexpr std::size_t length(const_pointer_t str) noexcept {
        return std::wcslen(str);
    }

    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        std::wmemcpy(dest, src, count);
    }

    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        std::wmemset(dest, ch, count);
    }

    static constexpr int compare(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        return std::wmemcmp(lhs, rhs, count);
    }

    static constexpr bool equal(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        return std::wmemcmp(lhs, rhs, count) == 0;
    }
};

template <>
struct string_trait<char8_t> {
    using char_t          = char8_t;
    using const_char_t    = const char8_t;
    using pointer_t       = char8_t*;
    using const_pointer_t = const char8_t*;

    constexpr static std::size_t type_size      = sizeof(char8_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
        while (str && str[n] != u8'\0') ++n;
        return n;
    }

    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        std::memcpy(dest, src, count * sizeof(char8_t));
    }

    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    static constexpr int compare(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        return std::memcmp(lhs, rhs, count * sizeof(char8_t));
    }

    static constexpr bool equal(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        return std::memcmp(lhs, rhs, count * sizeof(char8_t)) == 0;
    }
};

template <>
struct string_trait<char16_t> {
    using char_t          = char16_t;
    using const_char_t    = const char16_t;
    using pointer_t       = char16_t*;
    using const_pointer_t = const char16_t*;

    constexpr static std::size_t type_size      = sizeof(char16_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
                while (str && str[n] != u'\0') ++n;
        return n;
    }

    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = src[i];
    }

    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    static constexpr int compare(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i) {
            if (lhs[i] < rhs[i]) return -1;
            if (lhs[i] > rhs[i]) return 1;
        }
        return 0;
    }

    static constexpr bool equal(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<char32_t> {
    using char_t          = char32_t;
    using const_char_t    = const char32_t;
    using pointer_t       = char32_t*;
    using const_pointer_t = const char32_t*;

    constexpr static std::size_t type_size      = sizeof(char32_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
        while (str && str[n] != U'\0') ++n;
        return n;
    }

    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = src[i];
    }

    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    static constexpr int compare(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i) {
            if (lhs[i] < rhs[i]) return -1;
            if (lhs[i] > rhs[i]) return 1;
        }
        return 0;
    }

    static constexpr bool equal(const_pointer_t lhs, const_pointer_t rhs, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }
};

}

#endif // STRING_TRAIT_H