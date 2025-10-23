#ifndef STRING_TYPE_CONVERSION_H
#define STRING_TYPE_CONVERSION_H

#include "string.h"
#include "../types/tags.h"
#include "../utils/left_ptr_macro.h"

namespace ks::core::string::type_conversion {
        #define KSTD_STRING_TYPES(_) \
    _(string, char)          \
    _(wstring, wchar_t)      \
    _(u8string, char8_t)     \
    _(u16string, char16_t)   \
    _(u32string, char32_t)

    template <typename CharT>
    inline int string_to_int(const CharT* s) {
        if constexpr (std::is_same_v<CharT, char>) return std::stoi(s);
        else if constexpr (std::is_same_v<CharT, wchar_t>) return std::stoi(s);
        else if constexpr (std::is_same_v<CharT, char8_t>) return std::stoi(reinterpret_cast<const char*>(s));
        else if constexpr (std::is_same_v<CharT, char16_t>) return std::stoi(std::wstring(s, s + std::char_traits<char16_t>::length(s)));
        else if constexpr (std::is_same_v<CharT, char32_t>) return std::stoi(std::wstring(s, s + std::char_traits<char32_t>::length(s)));
        else static_assert(sizeof(CharT) == 0, "Unsupported char type");
    }

    template <typename CharT>
    inline float string_to_float(const CharT* s) {
        if constexpr (std::is_same_v<CharT, char>) return std::stof(s);
        else if constexpr (std::is_same_v<CharT, wchar_t>) return std::stof(s);
        else if constexpr (std::is_same_v<CharT, char8_t>) return std::stof(reinterpret_cast<const char*>(s));
        else if constexpr (std::is_same_v<CharT, char16_t>) return std::stof(std::wstring(s, s + std::char_traits<char16_t>::length(s)));
        else if constexpr (std::is_same_v<CharT, char32_t>) return std::stof(std::wstring(s, s + std::char_traits<char32_t>::length(s)));
        else static_assert(sizeof(CharT) == 0, "Unsupported char type");
    }

    template <typename CharT>
    inline double string_to_double(const CharT* s) {
        if constexpr (std::is_same_v<CharT, char>) return std::stod(s);
        else if constexpr (std::is_same_v<CharT, wchar_t>) return std::stod(s);
        else if constexpr (std::is_same_v<CharT, char8_t>) return std::stod(reinterpret_cast<const char*>(s));
        else if constexpr (std::is_same_v<CharT, char16_t>) return std::stod(std::wstring(s, s + std::char_traits<char16_t>::length(s)));
        else if constexpr (std::is_same_v<CharT, char32_t>) return std::stod(std::wstring(s, s + std::char_traits<char32_t>::length(s)));
        else static_assert(sizeof(CharT) == 0, "Unsupported char type");
    }

    template <typename CharT>
    inline bool string_to_bool(const CharT* s) {

    }


    #define DEFINE_STRING_OPS(STR_ALIAS, CHAR_T)                               \
    inline ksstd::STR_ALIAS &operator-(ksstd::STR_ALIAS &self) noexcept {        \
    return self;                                                           \
    }                                                                           \
    inline int operator<(types::tags::Int, ksstd::STR_ALIAS &self) noexcept {                 \
        return string_to_int<CHAR_T>(self.c_str());                             \
    }                                                                           \
    inline float operator<(types::tags::Float, ksstd::STR_ALIAS &self) noexcept {             \
        return string_to_float<CHAR_T>(self.c_str());                           \
    }                                                                           \
    inline double operator<(types::tags::Double, ksstd::STR_ALIAS &self) noexcept {           \
        return string_to_double<CHAR_T>(self.c_str());                          \
    }                                                                           \
    inline bool operator<(types::tags::Bool, ksstd::STR_ALIAS &self) noexcept {               \
        return string_to_bool<CHAR_T>(self.c_str());                            \
    }

    KSTD_STRING_TYPES(DEFINE_STRING_OPS)

    #undef DEFINE_STRING_OPS
    #undef KSTD_STRING_TYPES
}

#endif //STRING_TYPE_CONVERSION_H
