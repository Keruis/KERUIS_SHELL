#ifndef CHARACTER_TYPE_H
#define CHARACTER_TYPE_H

namespace ks::core::string::type {

enum class CharTypeId {
    Char,
    WChar,
    U8Char,
    U16Char,
    U32Char
};

#define CHAR_TYPES_LIST \
    X(string, char)     \
    X(wstring, wchar_t) \
    X(u8string, char8_t) \
    X(u16string, char16_t)\
    X(u32string, char32_t)

template <CharTypeId Id> struct CharTypeOf {};

template <> struct CharTypeOf<CharTypeId::Char>  {using type = char;};
template <> struct CharTypeOf<CharTypeId::WChar> {using type = wchar_t;};
template <> struct CharTypeOf<CharTypeId::U8Char>  {using type = char8_t;};
template <> struct CharTypeOf<CharTypeId::U16Char> {using type = char16_t;};
template <> struct CharTypeOf<CharTypeId::U32Char>  {using type = char32_t;};

using CharTypeList = std::integer_sequence<
    std::underlying_type_t<CharTypeId>,
    static_cast<std::underlying_type_t<CharTypeId>>(CharTypeId::Char),
    static_cast<std::underlying_type_t<CharTypeId>>(CharTypeId::WChar),
    static_cast<std::underlying_type_t<CharTypeId>>(CharTypeId::U8Char),
    static_cast<std::underlying_type_t<CharTypeId>>(CharTypeId::U16Char),
    static_cast<std::underlying_type_t<CharTypeId>>(CharTypeId::U32Char)
>;

template <typename Ty_, std::underlying_type_t<CharTypeId>... Ids>
constexpr bool is_char_type_impl(std::integer_sequence<std::underlying_type_t<CharTypeId>, Ids...>) {
    return (std::is_same_v<Ty_, typename CharTypeOf<static_cast<CharTypeId>(Ids)>::type> || ...);
}

template <typename Ty_>
constexpr bool is_char_type_v = is_char_type_impl<Ty_>(CharTypeList{});

}

#endif //CHARACTER_TYPE_H
