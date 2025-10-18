#ifndef STRING_CATEGORY_H
#define STRING_CATEGORY_H

#include <cstdint>

namespace ks::core::string::category {

using category_t = std::uint8_t;

enum class Category : category_t {
    isSmall = 0,
    isLarge = 1,
};

}

#endif //STRING_CATEGORY_H
