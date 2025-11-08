module;

#include <concepts>

export module ks.core.math.concepts:scalar;

export namespace ks::core::math::concepts {

template <typename Ty_>
concept Regular = std::regular<Ty_>;

template <typename Ty_>
concept Arithmetic =
    requires(Ty_ a, Ty_ b) {
        { a + b } -> std::same_as<Ty_>;
        { a - b } -> std::same_as<Ty_>;
        { a * b } -> std::same_as<Ty_>;
        { a / b } -> std::same_as<Ty_>;
    }
;

template <typename Ty_>
concept Scalar = Regular<Ty_> && Arithmetic<Ty_>;

}

