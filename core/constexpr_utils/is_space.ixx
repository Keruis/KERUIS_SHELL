module;

#include <type_traits>

export module ks.core.constexpr_utils.is_space;

export namespace ks::core::constexpr_utils {

    template <typename CharT>
    constexpr bool is_space(CharT c) {
        static_assert(std::is_integral_v<CharT>, "CharT must be a character type");

        return c == static_cast<CharT>(' ')  ||
               c == static_cast<CharT>('\t') ||
               c == static_cast<CharT>('\r') ||
               c == static_cast<CharT>('\n') ||
               c == static_cast<CharT>('\v') ||
               c == static_cast<CharT>('\f');
    }

}