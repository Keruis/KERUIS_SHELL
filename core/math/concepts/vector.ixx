module;

#include <concepts>
#include <iterator>

export module ks.core.math.concepts:vector;

export namespace ks::core::math::concepts {

template <typename T, typename Value>
concept pair_like = requires(T t) {
    { t.first } -> std::convertible_to<Value>;
    { t.second } -> std::convertible_to<Value>;
};

template <typename T, typename Value>
concept array2_like = requires(T t) {
    { t[0] } -> std::convertible_to<Value>;
    { t[1] } -> std::convertible_to<Value>;
};

template <typename T, typename Value>
concept vector2_like = requires(T t) {
    { t.x } -> std::convertible_to<Value>;
    { t.y } -> std::convertible_to<Value>;
};

template <typename T, typename Value>
concept initlist2_like = requires(T t) {
    { std::size(t) } -> std::same_as<std::size_t>;
    { *t.begin() } -> std::convertible_to<Value>;
};

}