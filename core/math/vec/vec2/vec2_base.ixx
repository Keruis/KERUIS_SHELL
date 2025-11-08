module;

#include <initializer_list>
#include <concepts>
#include "../../../utils/attributes.h"
#include "../../../utils/type_traits.h"

export module ks.core.math.vec.vector2:base;

import ks.core.math.concepts;
import ks.core.math.tag;

namespace ks::core::math::vec {

export template <concepts::Scalar Ty_> struct vector2 {
    Ty_ x;
    Ty_ y;

    using tag = tag::vector2_tag;
    using value_type = Ty_;
    using const_value_type = const Ty_;
    using floating_point_type = utils::traits::floating_point_type<Ty_>;
    using const_pass_type = utils::traits::conditional_pass_type<const vector2, sizeof(Ty_) * 2>;

    KS_CONSTEXPR vector2() KS_NOEXCEPT : x(0), y(0) {}
    KS_CONSTEXPR explicit vector2(Ty_ v) KS_NOEXCEPT : x(v), y(v) {}
    KS_CONSTEXPR vector2(Ty_ _x, Ty_ _y) KS_NOEXCEPT : x(_x), y(_y) {}
    template <std::convertible_to<Ty_> U_>
    KS_CONSTEXPR explicit vector2(const vector2<U_>& v) KS_NOEXCEPT : x(static_cast<Ty_>(v.x)), y(static_cast<Ty_>(v.y)) {}
    KS_CONSTEXPR vector2(std::initializer_list<Ty_> list) KS_NOEXCEPT {auto it = list.begin(); x = it != list.end() ? *it++ : Ty_(0); y = it != list.end() ? *it++ : Ty_(0);}
    static KS_CONSTEXPR vector2 zero() KS_NOEXCEPT {return vector2(0);}
    static KS_CONSTEXPR vector2 one() KS_NOEXCEPT {return vector2(1);}
    static KS_CONSTEXPR vector2 unit_x() KS_NOEXCEPT {return vector2(1,0);}
    static KS_CONSTEXPR vector2 unit_y() KS_NOEXCEPT {return vector2(0,1);}

    KS_NODISCARD KS_CONSTEXPR vector2 operator+() KS_CONST KS_NOEXCEPT {return *this;}
    KS_NODISCARD KS_CONSTEXPR vector2 operator-() KS_CONST KS_NOEXCEPT {return vector2(-x, -y);}

    KS_CONST KS_CONSTEXPR vector2& set(value_type ox, value_type oy) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& set(value_type ov) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& set_x(value_type ox) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& set_y(value_type oy) KS_NOEXCEPT;
    template <typename... Args>
    KS_CONSTEXPR vector2& set_of(Args&&... args) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& add(const_value_type ox, const_value_type oy) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& add(const_value_type ov) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& add_x(const_value_type ox) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& add_y(const_value_type oy) KS_NOEXCEPT;
    template <typename... Args>
    KS_CONSTEXPR vector2& add_of(Args&&... args) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& sub(const_value_type ox, const_value_type oy) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& sub(const_value_type ov) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& sub_x(const_value_type ox) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& sub_y(const_value_type oy) KS_NOEXCEPT;
    template <typename... Args>
    KS_CONSTEXPR vector2& sub_of(Args&&... args) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& mul(const_value_type ox, const_value_type oy) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& mul(const_value_type ov) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& mul_x(const_value_type ox) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& mul_y(const_value_type oy) KS_NOEXCEPT;
    template <typename... Args>
    KS_CONSTEXPR vector2& mul_of(Args&&... args) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& div(const_value_type ox, const_value_type oy) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& div(const_value_type ov) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& div_x(const_value_type ox) KS_NOEXCEPT;
    KS_CONST KS_CONSTEXPR vector2& div_y(const_value_type oy) KS_NOEXCEPT;
    template <typename... Args>
    KS_CONSTEXPR vector2& div_of(Args&&... args) KS_NOEXCEPT;

private:
    template <typename Vec>
    struct SetOp {
        static KS_CONSTEXPR void apply(Vec& v, value_type a, value_type b) {
            v.set(a, b);
        }
    };

    template <typename Vec>
    struct AddOp {
        using value_type = typename Vec::value_type;
        static KS_CONSTEXPR void apply(Vec& v, value_type a, value_type b) {
            v.add(a, b);
        }
    };

    template <typename Vec>
    struct SubOp {
        using value_type = typename Vec::value_type;
        static KS_CONSTEXPR void apply(Vec& v, value_type a, value_type b) {
            v.sub(a, b);
        }
    };

    template <typename Vec>
    struct MulOp {
        using value_type = typename Vec::value_type;
        static KS_CONSTEXPR void apply(Vec& v, value_type a, value_type b) {
            v.mul(a, b);
        }
    };

    template <typename Vec>
    struct DivOp {
        using value_type = typename Vec::value_type;
        static KS_CONSTEXPR void apply(Vec& v, value_type a, value_type b) {
            v.div(a, b);
        }
    };

    template <typename Op, typename Arg>
    KS_CONSTEXPR vector2& op_one(const Arg& arg) {
        if constexpr (concepts::pair_like<Arg, Ty_>) {
            Op::apply(*this, static_cast<Ty_>(arg.first), static_cast<Ty_>(arg.second));
        } else if constexpr (concepts::array2_like<Arg, Ty_>) {
            Op::apply(*this, static_cast<Ty_>(arg[0]), static_cast<Ty_>(arg[1]));
        } else if constexpr (concepts::vector2_like<Arg, Ty_>) {
            Op::apply(*this, static_cast<Ty_>(arg.x), static_cast<Ty_>(arg.y));
        } else if constexpr (concepts::initlist2_like<Arg, Ty_>) {
            auto it = arg.begin();
            Op::apply(*this, static_cast<Ty_>(*it), static_cast<Ty_>(*(it+1)));
        } else if constexpr (std::convertible_to<Arg, Ty_>) {
            Op::apply(*this, static_cast<Ty_>(arg), static_cast<Ty_>(arg));
        } else {
            static_assert(false, "Unsupported type in op_one");
        }
        return *this;
    }
    template <typename Op, bool HasPrev, typename Prev, typename Arg, typename... Rest>
    KS_CONSTEXPR vector2& process_of_impl(Prev prev, Arg&& arg, Rest&&... rest) KS_NOEXCEPT {
        using T = std::remove_cvref_t<Arg>;

        if constexpr (std::convertible_to<T, Ty_>) {
            if constexpr (HasPrev) {
                Op::apply(*this, static_cast<Ty_>(prev), static_cast<Ty_>(arg));
                if constexpr (sizeof...(Rest) > 0)
                    return process_of_impl<Op, false>(Ty_{}, std::forward<Rest>(rest)...);
                else
                    return *this;
            } else {
                if constexpr (sizeof...(Rest) > 0)
                    return process_of_impl<Op, true>(static_cast<Ty_>(arg), std::forward<Rest>(rest)...);
                else
                    return op_one<Op>(static_cast<Ty_>(arg));
            }
        } else {
            if constexpr (HasPrev)
                op_one<Op>(*this, prev);
            op_one<Op>(std::forward<Arg>(arg));
            if constexpr (sizeof...(Rest) > 0)
                return process_of_impl<Op, false>(Ty_{}, std::forward<Rest>(rest)...);
            else
                return *this;
        }
    }
    // template <typename Arg>
    // KS_CONST KS_CONSTEXPR vector2& set_one(const Arg& arg) KS_NOEXCEPT;
    // template <bool HasPrev, typename Prev, typename Arg, typename... Rest>
    // KS_CONSTEXPR vector2& set_of_impl(Prev prev, Arg&& arg, Rest&&... rest) KS_NOEXCEPT;
};



}