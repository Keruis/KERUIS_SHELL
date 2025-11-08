module;

#include <type_traits>
#include <algorithm>

#include "../../../utils/attributes.h"

export module ks.core.math.vec.vector2:impl;

import :base;
import ks.core.math.traits;

namespace ks::core::math::vec {

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::set(value_type ox, value_type oy) KS_NOEXCEPT {
    this->x = ox;
    this->y = oy;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::set(value_type ov) KS_NOEXCEPT {
    return this->set(ov, ov);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::set_x(value_type ox) KS_NOEXCEPT {
    this->x = ox;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::set_y(value_type oy)KS_NOEXCEPT {
    this->y = oy;
    return *this;
}

template <concepts::Scalar Ty_>
template <typename... Args>
KS_CONSTEXPR vector2<Ty_>& vector2<Ty_>::set_of(Args&&... args) KS_NOEXCEPT {
    //return set_of_impl<false>(value_type{}, std::forward<Args>(args)...);
    return process_of_impl<SetOp<vector2>, false>(value_type{}, std::forward<Args>(args)...);
}

// template <concepts::Scalar Ty_>
// template <typename Arg>
// KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::set_one(const Arg& arg) KS_NOEXCEPT {
//     if constexpr (concepts::pair_like<Arg, value_type>) {
//         this->set(arg.first, arg.second);
//     } else if constexpr (concepts::array2_like<Arg, value_type>) {
//         this->set(arg[0], arg[1]);
//     } else if constexpr (concepts::vector2_like<Arg, value_type>) {
//         this->set(arg.x, arg.y);
//     } else if constexpr (concepts::initlist2_like<Arg, value_type>) {
//         auto it = arg.begin();
//         this->set(*it, *(it+1));
//     } else {
//         this->set(arg);
//     }
//     return *this;
// }
//
// template <concepts::Scalar Ty_>
// template <bool HasPrev, typename Prev, typename Arg, typename... Rest>
// KS_CONSTEXPR vector2<Ty_>& vector2<Ty_>::set_of_impl(Prev prev, Arg&& arg, Rest&&... rest) KS_NOEXCEPT {
//     using T = std::remove_cvref_t<Arg>;
//
//     if constexpr (std::convertible_to<T, value_type>) {
//         if constexpr (HasPrev) {
//             this->set(static_cast<value_type>(prev), static_cast<value_type>(arg));
//             if constexpr (sizeof...(Rest) > 0)
//                 return set_of_impl<false>(value_type{}, std::forward<Rest>(rest)...);
//             else
//                 return *this;
//         } else {
//             if constexpr (sizeof...(Rest) > 0)
//                 return set_of_impl<true>(static_cast<value_type>(arg), std::forward<Rest>(rest)...);
//             else {
//                 return set_one(static_cast<value_type>(arg));
//             }
//         }
//     } else {
//         if constexpr (HasPrev)
//             set_one(prev);
//         set_one(std::forward<Arg>(arg));
//         if constexpr (sizeof...(Rest) > 0)
//             return set_of_impl<false>(value_type{}, std::forward<Rest>(rest)...);
//         else
//             return *this;
//     }
// }

// template <concepts::Scalar Ty_>
// template <typename First, typename... Rest>
// KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::set_of(First&& first, Rest&&... rest) KS_NOEXCEPT
//     requires (!(sizeof...(Rest) == 0 && std::convertible_to<First, value_type>))
// {
//     struct State {
//         bool has_prev = false;
//         value_type prev{};
//     } st;
//
//     auto process_one = [&]<typename T0>(T0&& v) KS_NOEXCEPT {
//         using ArgT = std::remove_cvref_t<T0>;
//
//         if constexpr (std::convertible_to<ArgT, value_type>) {
//             if (st.has_prev) {
//                 this->set(st.prev, static_cast<value_type>(v));
//                 st.has_prev = false;
//             } else {
//                 st.prev = static_cast<value_type>(v);
//                 st.has_prev = true;
//             }
//         } else {
//             if (st.has_prev) {
//                 set_one(st.prev);
//                 st.has_prev = false;
//             }
//             set_one(std::forward<T0>(v));
//         }
//     };
//
//     process_one(std::forward<First>(first));
//     (process_one(std::forward<Rest>(rest)), ...);
//
//     if (st.has_prev) set_one(st.prev);
//
//     return *this;
// }

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::add(const_value_type ox, const_value_type oy) KS_NOEXCEPT {
    this->x += ox;
    this->y += oy;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::add(const_value_type ov) KS_NOEXCEPT {
    return this->add(ov, ov);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::add_x(const_value_type ox) KS_NOEXCEPT {
    this->x += ox;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::add_y(const_value_type oy) KS_NOEXCEPT {
    this->y += oy;
    return *this;
}

template <concepts::Scalar Ty_>
template <typename... Args>
KS_CONSTEXPR vector2<Ty_>& vector2<Ty_>::add_of(Args&&... args) KS_NOEXCEPT {
    return process_of_impl<AddOp<vector2>, false>(value_type{}, std::forward<Args>(args)...);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::sub(const_value_type ox, const_value_type oy) KS_NOEXCEPT {
    this->x -= ox;
    this->y -= oy;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::sub(const_value_type ov) KS_NOEXCEPT {
    return this->sub(ov, ov);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::sub_x(const_value_type ox) KS_NOEXCEPT {
    this->x -= ox;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::sub_y(const_value_type oy) KS_NOEXCEPT {
    this->y -= oy;
    return *this;
}

template <concepts::Scalar Ty_>
template <typename... Args>
KS_CONSTEXPR vector2<Ty_>& vector2<Ty_>::sub_of(Args&&... args) KS_NOEXCEPT {
    return process_of_impl<SubOp<vector2>, false>(value_type{}, std::forward<Args>(args)...);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::mul(const_value_type ox, const_value_type oy) KS_NOEXCEPT {
    this->x *= ox;
    this->y *= oy;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::mul(const_value_type ov) KS_NOEXCEPT {
    return this->mul(ov, ov);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::mul_x(const_value_type ox) KS_NOEXCEPT {
    this->x *= ox;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::mul_y(const_value_type oy) KS_NOEXCEPT {
    this->y *= oy;
    return *this;
}

template <concepts::Scalar Ty_>
template <typename... Args>
KS_CONSTEXPR vector2<Ty_>& vector2<Ty_>::mul_of(Args&&... args) KS_NOEXCEPT {
    return process_of_impl<MulOp<vector2>, false>(value_type{}, std::forward<Args>(args)...);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::div(const_value_type ox, const_value_type oy) KS_NOEXCEPT {
    this->x /= ox;
    this->y /= oy;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::div(const_value_type ov) KS_NOEXCEPT {
    return this->div(ov, ov);
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::div_x(const_value_type ox) KS_NOEXCEPT {
    this->x *= ox;
    return *this;
}

template <concepts::Scalar Ty_>
KS_CONSTEXPR KS_CONST vector2<Ty_>& vector2<Ty_>::div_y(const_value_type oy) KS_NOEXCEPT {
    this->y *= oy;
    return *this;
}

template <concepts::Scalar Ty_>
template <typename... Args>
KS_CONSTEXPR vector2<Ty_>& vector2<Ty_>::div_of(Args&&... args) KS_NOEXCEPT {
    return process_of_impl<DivOp<vector2>, false>(value_type{}, std::forward<Args>(args)...);
}

}