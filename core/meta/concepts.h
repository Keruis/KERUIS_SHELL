#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <type_traits>
#include <concepts>


namespace ks::core::meta {

template <typename T>
concept appendable_basic_string = requires { typename T::string_trait_t; };

}

#endif //CONCEPTS_H
