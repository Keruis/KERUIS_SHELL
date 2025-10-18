#ifndef CHARACTER_TYPE_H
#define CHARACTER_TYPE_H
#include <tuple>

namespace ks::core::string::type {

using character_type = std::tuple<
    char,
    wchar_t
>;

}

#endif //CHARACTER_TYPE_H
