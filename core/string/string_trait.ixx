module;

#include "../utils/type_traits.h"
#include "types/character_type.h"

#include <string>
#include <cstring>
#include <cwchar>
#include <cstddef>

export module ks.core.string.string_trait;

export namespace ks::core::string::trait {

template <typename Ty_>
concept character_type = type::is_char_type_v<Ty_>;

template <character_type Ty_>
struct string_trait {
    using char_t            = Ty_;
    using const_char_t      = const Ty_;
    using reference_t       = Ty_&;
    using const_reference_t = const reference_t;
    using pointer_t         = char_t*;
    using const_pointer_t   = const_char_t*;

    constexpr static std::size_t type_size      = sizeof(char_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    template <class = void>
    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
        if (!str) return 0;
        while (str[n] != char_t(0)) ++n;
        return n;
    }

    template <class = void>
    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = src[i];
    }

    template <class = void>
    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    template <class = void>
    static constexpr bool compare(char_t ch1, char_t ch2) noexcept {
        return ch1 == ch2;
    }

    template <class = void>
    static constexpr bool compare(const_pointer_t str1, const_pointer_t str2, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<char> {
    using char_t            = char;
    using const_char_t      = const char;
    using reference_t       = char&;
    using const_reference_t = const char&;
    using pointer_t         = char*;
    using const_pointer_t   = const char*;

    constexpr static std::size_t type_size      = sizeof(char);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    template <class = void>
    static constexpr std::size_t length(const_pointer_t str) noexcept {
        return std::strlen(str);
    }

    template <class = void>
    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        std::memcpy(dest, src, count);
    }

    template <class = void>
    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        std::memset(dest, ch, count);
    }

    template <class = void>
    static constexpr bool compare(char_t ch1, char_t ch2) noexcept {
        return ch1 == ch2;
    }

    template <class = void>
    static constexpr bool compare(const_pointer_t str1, const_pointer_t str2, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<wchar_t> {
    using char_t            = wchar_t;
    using const_char_t      = const wchar_t;
    using reference_t       = wchar_t&;
    using const_reference_t = const wchar_t&;
    using pointer_t         = wchar_t*;
    using const_pointer_t   = const wchar_t*;

    constexpr static std::size_t type_size      = sizeof(wchar_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    template <class = void>
    static constexpr std::size_t length(const_pointer_t str) noexcept {
        return std::wcslen(str);
    }

    template <class = void>
    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        std::wmemcpy(dest, src, count);
    }

    template <class = void>
    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        std::wmemset(dest, ch, count);
    }

    template <class = void>
    static constexpr bool compare(char_t ch1, char_t ch2) noexcept {
        return ch1 == ch2;
    }

    template <class = void>
    static constexpr bool compare(const_pointer_t str1, const_pointer_t str2, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<char8_t> {
    using char_t            = char8_t;
    using const_char_t      = const char8_t;
    using reference_t       = char8_t&;
    using const_reference_t = const char8_t;
    using pointer_t         = char8_t*;
    using const_pointer_t   = const char8_t*;

    constexpr static std::size_t type_size      = sizeof(char8_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    template <class = void>
    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
        while (str && str[n] != u8'\0') ++n;
        return n;
    }

    template <class = void>
    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        std::memcpy(dest, src, count * sizeof(char8_t));
    }

    template <class = void>
    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    template <class = void>
    static constexpr bool compare(char_t ch1, char_t ch2) noexcept {
        return ch1 == ch2;
    }

    template <class = void>
    static constexpr bool compare(const_pointer_t str1, const_pointer_t str2, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<char16_t> {
    using char_t            = char16_t;
    using const_char_t      = const char16_t;
    using reference_t       = char16_t&;
    using const_reference_t = const char16_t;
    using pointer_t         = char16_t*;
    using const_pointer_t   = const char16_t*;

    constexpr static std::size_t type_size      = sizeof(char16_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    template <class = void>
    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
                while (str && str[n] != u'\0') ++n;
        return n;
    }

    template <class = void>
    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = src[i];
    }

    template <class = void>
    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    template <class = void>
    static constexpr bool compare(char_t ch1, char_t ch2) noexcept {
        return ch1 == ch2;
    }

    template <class = void>
    static constexpr bool compare(const_pointer_t str1, const_pointer_t str2, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};

template <>
struct string_trait<char32_t> {
    using char_t            = char32_t;
    using const_char_t      = const char32_t;
    using reference_t       = char32_t&;
    using const_reference_t = const char32_t;
    using pointer_t         = char32_t*;
    using const_pointer_t   = const char32_t*;

    constexpr static std::size_t type_size      = sizeof(char32_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask  = 1;
    constexpr static std::size_t capacity_mask  = ~category_mask;

    template <class = void>
    static constexpr std::size_t length(const_pointer_t str) noexcept {
        std::size_t n = 0;
        while (str && str[n] != U'\0') ++n;
        return n;
    }

    template <class = void>
    static constexpr void copy(pointer_t dest, const_pointer_t src, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = src[i];
    }

    template <class = void>
    static constexpr void assign(pointer_t dest, std::size_t count, char_t ch) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            dest[i] = ch;
    }

    template <class = void>
    static constexpr bool compare(char_t ch1, char_t ch2) noexcept {
        return ch1 == ch2;
    }

    template <class = void>
    static constexpr bool compare(const_pointer_t str1, const_pointer_t str2, std::size_t count) noexcept {
        for (std::size_t i = 0; i < count; ++i)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};

}