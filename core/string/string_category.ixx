module;

#include <cstdint>

export module ks.core.string.string_category;

export namespace ks::core::string::category {

    using category_t = std::uint8_t;

    enum class Category : category_t {
        isSmall = 0,
        isMedium = 1,
    };

}