#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H
#include <tuple>
#include <type_traits>

namespace ks::core::utils::traits {

template <typename Ty_, typename... Ts_>
constexpr bool is_any_of_v = (std::is_same_v<Ty_, Ts_> || ...);

template <typename Ty_, typename Tuple_>
struct is_in_tuple;

template <typename Ty_, typename... Ts_>
struct is_in_tuple<Ty_, std::tuple<Ts_...>>
    : std::bool_constant<is_any_of_v<Ty_, Ts_...>> {};

template <typename Ty_, typename Tuple_>
constexpr bool is_in_tuple_v = is_in_tuple<Ty_, Tuple_>::value;

}

#endif //TYPE_TRAITS_H
