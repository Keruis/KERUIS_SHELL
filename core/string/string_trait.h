#ifndef STRING_TRAIT_H
#define STRING_TRAIT_H

#include "../utils/type_traits.h"
#include "character_type.h"

namespace ks::core::string::trait {

template <typename Ty_>
constexpr bool is_character_type = core::utils::traits::is_in_tuple_v<
    Ty_,
    type::character_type
>;

template <typename Ty_>
concept character_type = is_character_type<Ty_>;

template <character_type Ty_>
struct string_trait {
    using char_t = Ty_;
    using const_char_t = const Ty_;
    using pointer = char_t*;
    using const_pointer = const char_t*;
    constexpr static std::size_t type_size = sizeof(char_t);
    constexpr static std::size_t category_shift = 1;
    constexpr static std::size_t category_mask = 1;
    constexpr static std::size_t capacity_mask = ~category_mask;
};

}

#endif //STRING_TRAIT_H
