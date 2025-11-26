module;

#include <cstddef>
#include <algorithm>

export module ks.core.constexpr_utils.string_literal;

template <std::size_t N>
struct string_literal {
    char value[N]{};

    explicit constexpr string_literal(char const (&str)[N]) {
        std::copy_n(str, N, value);
    }

    constexpr bool operator==(const string_literal& other) const {
        for (std::size_t i = 0; i < N; ++i)
            if (value[i] != other.value[i]) return false;
        return true;
    }
};

template<std::size_t N>
string_literal(char const (&)[N]) -> string_literal<N>;