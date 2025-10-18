#ifndef STRING_BOX_H
#define STRING_BOX_H

#include <cstddef>
#include <cstdint>

#include "string_category.h"

#include "../utils/attributes.h"

namespace ks::core::string::box {

template <typename StringTrait_>
struct string_box {

    using char_t                                = typename StringTrait_::char_t;
    using pointer_t                             = typename StringTrait_::pointer_t;
    constexpr static std::size_t type_size      = StringTrait_::type_size;
    constexpr static std::size_t category_mask  = StringTrait_::category_mask;
    constexpr static std::size_t capacity_mask  = StringTrait_::capacity_mask;


    constexpr string_box() KS_NOEXCEPT = default;
    constexpr ~string_box() KS_NOEXCEPT = default;

    struct MediumLarge {
        pointer_t data_;
        std::size_t size_;
        std::size_t capacity_;

        KS_NODISCARD std::size_t capacity() KS_CONST KS_NOEXCEPT {
            return capacity_ & ~capacity_mask;
        }

        void setCapacity(std::size_t cap, category::Category cat) KS_NOEXCEPT {
            capacity_ = (cap & capacity_mask)
            | ((cat == category::Category::isLarge) ? category_mask : 0);
        }
    };

    constexpr static std::size_t medium_large_size = sizeof(MediumLarge);

    union {
        uint8_t bytes_[medium_large_size];
        MediumLarge as_ml;
        char_t as_small[medium_large_size/type_size];
    };

    category::Category category() KS_CONST KS_NOEXCEPT {
        return (as_ml.capacity_ & category_mask)
            ? category::Category::isLarge
            : category::Category::isSmall;
    }

};

}



#endif //STRING_BOX_H
