#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H
#include <tuple>
#include <type_traits>

namespace ks::core::utils::traits {

template <typename> inline constexpr bool always_false_v = false;

template <typename Ty_, typename... Ts_>
constexpr bool is_any_of_v = (std::is_same_v<Ty_, Ts_> || ...);

template <typename Ty_, typename Tuple_>
struct is_in_tuple;

template <typename Ty_, typename... Ts_>
struct is_in_tuple<Ty_, std::tuple<Ts_...>>
    : std::bool_constant<is_any_of_v<Ty_, Ts_...>> {};

template <typename Ty_, typename Tuple_>
constexpr bool is_in_tuple_v = is_in_tuple<Ty_, Tuple_>::value;

template <typename Ty_, std::size_t N_>
using conditional_pass_type = std::conditional_t<N_ <= 16, Ty_, const Ty_&>;

template <typename Ty_>
using floating_point_type = std::conditional_t<std::floating_point<Ty_>, Ty_,
    std::conditional_t<sizeof(Ty_) <= 4,
    float, double
>>;

}

#endif //TYPE_TRAITS_H
