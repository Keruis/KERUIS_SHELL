export module ks.core.math.vec.vector2:ops;

import :base;
#include "../../../utils/attributes.h"

namespace ks::core::math::vec {

export template <typename Ty_>
KS_ALWAYS_INLINE KS_CONSTEXPR vector2<Ty_> operator+(const vector2<Ty_>& a, const vector2<Ty_>& b) KS_NOEXCEPT {
    return vector2<Ty_>(a.x + b.x, a.y + b.y);
}

export template <typename Ty_>
KS_ALWAYS_INLINE KS_CONSTEXPR vector2<Ty_> operator+(const vector2<Ty_>& a, Ty_ b) KS_NOEXCEPT {
    return vector2<Ty_>(a.x + b, a.y + b);
}

export template <typename Ty_>
KS_ALWAYS_INLINE KS_CONSTEXPR vector2<Ty_> operator-(const vector2<Ty_>& a, const vector2<Ty_>& b) KS_NOEXCEPT {
    return vector2<Ty_>(a.x - b.x, a.y - b.y);
}

export template <typename Ty_>
KS_ALWAYS_INLINE KS_CONSTEXPR vector2<Ty_> operator-(const vector2<Ty_>& a, Ty_ b) KS_NOEXCEPT {
    return vector2<Ty_>(a.x - b, a.y - b);
}

}
