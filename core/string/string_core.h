#ifndef STRING_CORE_H
#define STRING_CORE_H

#include <memory>
#include <cstring>

#include "string_box.h"
#include "string_category.h"

#include "../utils/attributes.h"
#include "../memory/allocator.h"

namespace ks::core::string::core {

template <typename StringTrait_, typename Alloc_ = memory::allocator::allocator<typename StringTrait_::char_t>>
class string_core : protected box::string_box<StringTrait_> {
public:
    using string_trait      = StringTrait_;
    using char_t            = typename string_trait::char_t;
    using const_char_t      = typename string_trait::const_char_t;
    using pointer_t         = typename string_trait::pointer_t;
    using const_pointer_t   = typename string_trait::const_pointer_t;
    using Alloc_t           = Alloc_;

    //constexpr static std::size_t nops = static_cast<std::size_t>(-1);

protected:
    using box_t             = box::string_box<string_trait>;
    using box_t::as_ml;
    using box_t::as_small;
    using box_t::type_size;
    using box_t::box_value_t;
    using box_t::box_buffer_t;

private:
    constexpr static std::size_t last_char = sizeof(as_ml) - 1;
    constexpr static std::size_t max_small_size = last_char / type_size;

public:
    KS_CONSTEXPR string_core() KS_NOEXCEPT;
    KS_CONSTEXPR ~string_core() KS_NOEXCEPT;
    KS_CONSTEXPR string_core(string_core&& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR explicit string_core(char_t ch) KS_NOEXCEPT;
    KS_CONSTEXPR string_core(const string_core& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR explicit string_core(const_pointer_t data) KS_NOEXCEPT;
    KS_CONSTEXPR string_core(const string_core& lhs, char_t ch) KS_NOEXCEPT;
    KS_CONSTEXPR string_core(const string_core& lhs, const_pointer_t data) KS_NOEXCEPT;
    KS_CONSTEXPR string_core(const string_core& lhs, const string_core& rhs) KS_NOEXCEPT;

private:
    KS_CONSTEXPR void reset() KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool isSmall() KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool isSmall() KS_CONST KS_NOEXCEPT;
    void setSmallSize(std::size_t s);
    template <bool init_heap>
    KS_CONSTEXPR void respace(std::size_t size) KS_NOEXCEPT;
    void initSmall(const_pointer_t data, std::size_t size);
    void initMedium(const_pointer_t data, std::size_t size);
    KS_CONSTEXPR void initSmall(const string_core& obj, const_pointer_t data, std::size_t size);
    KS_CONSTEXPR void initMedium(const string_core& obj, const_pointer_t data, std::size_t size);
    void copySmall(const string_core& rhs);
    void copyMedium(const string_core& rhs);
    void reserveSmall(std::size_t size);
    void reserveMedium(std::size_t size);
    void swapSmall(const string_core& rhs);
    void swapMedium(const string_core& rhs);
    void clearSmall() KS_NOEXCEPT;
    void clearMedium() KS_NOEXCEPT;
    KS_CONSTEXPR bool compare(char_t ch) KS_NOEXCEPT;
    KS_CONSTEXPR bool compare(const_pointer_t str) KS_NOEXCEPT;
    KS_CONSTEXPR void appendSmall(const_pointer_t data, std::size_t size) KS_NOEXCEPT;
    KS_CONSTEXPR void appendMedium(const_pointer_t data, std::size_t size) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& append(char_t ch)                  KS_NOEXCEPT;
    KS_CONSTEXPR string_core& append(const_pointer_t data)       KS_NOEXCEPT;
    KS_CONSTEXPR string_core& append(const string_core& rhs)     KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignmentSmall(const_pointer_t data, std::size_t size) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignmentMedium(const_pointer_t data, std::size_t size) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignment(const_pointer_t data, std::size_t size) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignment(char_t ch) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignment(const_pointer_t data) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignment(const string_core& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& assignment(string_core&& rhs) KS_NOEXCEPT;

public:
    KS_NODISCARD KS_CONSTEXPR std::size_t       size()      KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR std::size_t       size()      KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR std::size_t       capacity()  KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool              empty()     KS_NOEXCEPT;
    KS_CONSTEXPR              void              clear()     KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR pointer_t         data()      KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_pointer_t   data()      KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR pointer_t         c_str()     KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_pointer_t   c_str()     KS_CONST KS_NOEXCEPT;
    KS_CONSTEXPR              void              swap(const string_core& rhs)  KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR pointer_t         begin()     KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_pointer_t   begin()     KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR pointer_t         end()       KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_pointer_t   end()       KS_CONST KS_NOEXCEPT;
    KS_CONSTEXPR void       reserve     (std::size_t size)           KS_NOEXCEPT;
    KS_CONSTEXPR void       push_back   (char_t ch)                  KS_NOEXCEPT;
    KS_CONSTEXPR void       push_back   (const_pointer_t data)       KS_NOEXCEPT;
    KS_CONSTEXPR char_t     pop_back    ()                           KS_NOEXCEPT;
    template <typename... Args>
    KS_CONSTEXPR string_core& append(Args&&... args) KS_NOEXCEPT;
};













template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core() KS_NOEXCEPT {
    reset();
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::~string_core() KS_NOEXCEPT {
    if (isSmall()) {
        return;
    }

    Alloc_t::deallocate(as_ml.data_, as_ml.capacity_);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(string_core&& rhs) KS_NOEXCEPT {
    as_ml = rhs.as_ml;
    rhs.reset();
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(char_t ch) KS_NOEXCEPT {
    reset(1);
    as_small[0] = ch;
}


template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(const string_core& rhs) KS_NOEXCEPT {
    switch (rhs.category()) {
        case category::Category::isSmall:
            copySmall(rhs);
            break;
        case category::Category::isMedium:
            copyMedium(rhs);
            break;
        default: ;
    }
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(const string_core& lhs, char_t ch) KS_NOEXCEPT {
    category::Category cat = lhs.size() + 1 <= max_small_size ? category::Category::isSmall : category::Category::isMedium;
    switch (cat) {
    case category::Category::isSmall:
        initSmall(lhs, &ch, 1);
        break;
    case category::Category::isMedium:
        initMedium(lhs, &ch, 1);
        break;
    default: ;
    }
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(const string_core& lhs, const_pointer_t data) KS_NOEXCEPT {
    category::Category cat = lhs.size() + 1 <= max_small_size ? category::Category::isSmall : category::Category::isMedium;
    switch (cat) {
    case category::Category::isSmall:
        initSmall(lhs, data, string_trait::length(data));
        break;
    case category::Category::isMedium:
        initMedium(lhs, data, string_trait::length(data));
        break;
    default: ;
    }
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(const string_core& lhs, const string_core& rhs) KS_NOEXCEPT {
    category::Category cat = lhs.size() + rhs.size() <= max_small_size ? category::Category::isSmall : category::Category::isMedium;
    switch (cat) {
    case category::Category::isSmall:
        initSmall(lhs, rhs.begin(), rhs.size());
        break;
    case category::Category::isMedium:
        initMedium(lhs, rhs.begin(), rhs.size());
        break;
    default: ;
    }
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>::string_core(const_pointer_t data) KS_NOEXCEPT {
    if (data == nullptr) {
        reset();
        return;
    }

    if (string_trait::length(data) < max_small_size) {
        initSmall(data, string_trait::length(data));
    } else {
        initMedium(data, string_trait::length(data));
    }
}


template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::reset() KS_NOEXCEPT {
    setSmallSize(0);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR bool string_core<StringTrait_, Alloc_>::isSmall() KS_NOEXCEPT {
    return box_t::category() == category::Category::isSmall;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR bool string_core<StringTrait_, Alloc_>::isSmall() KS_CONST KS_NOEXCEPT {
    return box_t::category() == category::Category::isSmall;
}


template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::setSmallSize(std::size_t s) {
    as_small[max_small_size] = s;
    as_small[s] = char_t();
}

template <typename StringTrait_, typename Alloc_>
template <bool init_heap>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::respace(std::size_t size) KS_NOEXCEPT {
    const std::size_t old_size = this->size();

    if constexpr (init_heap) {
        pointer_t new_data = Alloc_t::allocate(size);
        string_trait::copy(new_data, as_small, old_size);
        as_ml.data_ = new_data;
        as_ml.data_[old_size] = char_t();
    } else {
        pointer_t old_pointer = as_ml.data_;
        const std::size_t old_capacity = as_ml.capacity();
        as_ml.data_ = Alloc_t::allocate(size);
        string_trait::copy(as_ml.data_, old_pointer, old_size);
        Alloc_t::deallocate(old_pointer, old_capacity);
    }

    as_ml.setCapacity(size, category::Category::isMedium);
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::initSmall(const_pointer_t data, std::size_t size) {
    setSmallSize(size);
    string_trait::copy(as_small, data, size);
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::initMedium(const_pointer_t data, std::size_t size) {
    as_ml.data_ = Alloc_t::allocate(size + 1);
    string_trait::copy(as_ml.data_, data, size);
    as_ml.data_[size] = char_t(0);
    as_ml.size_ = size;
    as_ml.setCapacity(size + 1, category::Category::isMedium);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::initSmall(const string_core& obj, const_pointer_t data, std::size_t size) {
    std::size_t obj_size = obj.size();
    setSmallSize(size + obj_size);
    string_trait::copy(as_small, obj.begin(), obj_size);
    string_trait::copy(as_small + obj_size, data, size);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::initMedium(const string_core& obj, const_pointer_t data, std::size_t size) {
    std::size_t obj_size = obj.size();
    as_ml.data_ = Alloc_t::allocate(size + obj_size + 1);
    string_trait::copy(as_small, obj.begin(), obj_size);
    string_trait::copy(as_small + obj.size(), data, size);
    as_ml.data_[size + obj_size] = char_t();
    as_ml.size_ = size + obj_size;
    as_ml.setCapacity(size + obj_size + 1, category::Category::isMedium);
}


template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::copySmall(const string_core& rhs) {
    as_ml = rhs.as_ml;
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::copyMedium(const string_core& rhs) {
    as_ml.data_ = Alloc_t::allocate(rhs.as_ml.size_ + 1);
    string_trait::copy(as_ml.data_, rhs.as_ml.data_, rhs.as_ml.size_ + 1);
    as_ml.size_ = rhs.as_ml.size_;
    as_ml.setCapacity((rhs.as_ml.size_ + 1) / type_size - 1, category::Category::isMedium);
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::reserveSmall(std::size_t size) {
    if (size < max_small_size) {
        return;
    }

    const std::size_t old_size = this->size();

    pointer_t mallocPtr = Alloc_t::allocate(size + 1);
    string_trait::copy(mallocPtr, as_small, old_size);
    as_ml.data_ = mallocPtr;
    as_ml.size_ = old_size;
    as_ml.setCapacity(size + 1, category::Category::isMedium);
    as_ml.data_[old_size] = char_t();
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::reserveMedium(std::size_t size) {
    if (size <= as_ml.capacity_) {
        return;
    }

    const std::size_t old_size = this->size();

    pointer_t mallocPtr = Alloc_t::allocate(size + 1);
    string_trait::copy(mallocPtr, as_ml.data_, old_size);
    as_ml.data_ = mallocPtr;
    as_ml.size_ = old_size;
    as_ml.setCapacity(size + 1, category::Category::isMedium);
    as_ml.data_[old_size] = char_t();
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::swapSmall(const string_core& rhs) {
    if (this == &rhs) {
        return;
    }

    if (isSmall()) {
        box_buffer_t tmp = this->as_small;
        this->as_small = rhs.as_small;
        rhs.as_small = tmp;
    } else {
        box_buffer_t tmp_buffer = rhs.as_small;
        box_value_t tmp_value = this->as_ml;
        rhs.as_ml = tmp_value;
        this->as_small = tmp_buffer;
    }
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::swapMedium(const string_core& rhs) {
    if (this == &rhs) {
        return;
    }

    if (isSmall()) {
        box_buffer_t tmp_buffer = this->as_small;
        box_value_t tmp_value = rhs.as_small;
        rhs.as_small = tmp_buffer;
        this->as_ml = tmp_value;
    } else {
        box_value_t tmp = this->as_ml;
        this->as_ml = rhs.as_ml;
        rhs.as_ml = tmp;
    }
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::clearSmall() KS_NOEXCEPT {
    as_small = 0;
    as_small[0] = char_t();
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::clearMedium() KS_NOEXCEPT {
    as_ml.size_ = 0;
    if (as_ml.data_) {
        as_ml.data_[0] = char_t();
    }
}


template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR bool string_core<StringTrait_, Alloc_>::compare(char_t ch) KS_NOEXCEPT {
    if (string_trait::length(as_ml.data_) != 1) {
        return false;
    }
    return string_trait::compare(as_ml.data_[0], ch);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR bool string_core<StringTrait_, Alloc_>::compare(const_pointer_t str) KS_NOEXCEPT {
    if (string_trait::length(str) != string_trait::length(as_ml.data_)) {
        return false;
    }
    return string_trait::compare(as_ml.data_, str, string_trait::length(str));
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::appendSmall(const_pointer_t data, std::size_t size) KS_NOEXCEPT {
    const std::size_t old_size = this->size();
    string_trait::copy(as_small + old_size, data, size);
    setSmallSize(old_size + size);
}

    template <typename StringTrait_, typename Alloc_>
    KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::appendMedium(const_pointer_t data, std::size_t size) KS_NOEXCEPT {
        std::cout << "[appendMedium] this=" << this
                  << ", data_=" << static_cast<void*>(as_ml.data_)
                  << ", size=" << this->size()
                  << ", append_size=" << size
                  << ", capacity=" << capacity()
                  << std::endl;

        if (capacity() < this->size() + size + 1) {
            reserve(this->size() + size + 1);
            std::cout << "[appendMedium] after reserve, data_=" << static_cast<void*>(as_ml.data_) << std::endl;
        }

        std::cout << "[appendMedium] this=" << this
           << ", data_=" << static_cast<void*>(as_ml.data_)
           << ", size=" << this->size()
           << ", append_size=" << size
           << ", capacity=" << capacity()
           << std::endl;

        string_trait::copy(as_ml.data_ + this->size(), data, size);

        as_ml.size_ += size;
        as_ml.data_[this->size()] = char_t();

        std::cout << "[appendMedium] after copy, data_=" << static_cast<void*>(as_ml.data_)
                  << ", new_size=" << this->size() << std::endl;
    }
template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignmentSmall(const_pointer_t data, std::size_t size) KS_NOEXCEPT {
    string_trait::copy(as_ml.data_, data, size);
    setSmallSize(size);
    return *this;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignmentMedium(const_pointer_t data, std::size_t size) KS_NOEXCEPT {
    string_trait::copy(as_ml.data_, data, size);
    as_ml.size_ = size;
    return *this;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignment(const_pointer_t data, std::size_t size) KS_NOEXCEPT {
    if (capacity() < as_ml.size_ + size + 1) {
        reserve(as_ml.size_ + size + 1);
    }
    if (isSmall()) {
        return assignSmall(data, size);
    }
    return assignMedium(data, size);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignment(char_t ch) KS_NOEXCEPT {
    return assignment(&ch, 1);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignment(const_pointer_t data) KS_NOEXCEPT {
    return assignment(data, string_trait::length(data));
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignment(const string_core& rhs) KS_NOEXCEPT {
    clear();
    append(rhs);
    return *this;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::assignment(string_core&& rhs) KS_NOEXCEPT {
    swap(rhs);
    return *this;
}


template <typename StringTrait_, typename Alloc_>
KS_NODISCARD KS_CONSTEXPR std::size_t string_core<StringTrait_, Alloc_>::size() KS_NOEXCEPT {
    if (isSmall()) {
        return static_cast<std::size_t>(as_small[max_small_size]);
    }
    return as_ml.size_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR std::size_t string_core<StringTrait_, Alloc_>::size() KS_CONST KS_NOEXCEPT {
    if (isSmall()) {
        return static_cast<std::size_t>(as_small[max_small_size]);
    }
    return as_ml.size_;
}


template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR std::size_t string_core<StringTrait_, Alloc_>::capacity() KS_NOEXCEPT {
    if (isSmall()) {
        return max_small_size;
    }
    return as_ml.capacity_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR bool string_core<StringTrait_, Alloc_>::empty() KS_NOEXCEPT {
    if (isSmall()) {
        return as_small[max_small_size] == 0;
    }
    return as_ml.size_ == 0;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::clear() KS_NOEXCEPT {
    if (isSmall()) {
        clearSmall();
    }
    clearMedium();
}


template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::pointer_t string_core<StringTrait_, Alloc_>::data() KS_NOEXCEPT {
    if (isSmall()) {
        return as_small;
    }
    return as_ml.data_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::const_pointer_t string_core<StringTrait_, Alloc_>::data() KS_CONST KS_NOEXCEPT {
    if (isSmall()) {
        return as_small;
    }
    return as_ml.data_;
}

template <typename StringTrait_, typename Alloc_>
KS_NODISCARD KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::pointer_t string_core<StringTrait_, Alloc_>::c_str() KS_NOEXCEPT {
    pointer_t ptr = as_ml.data_;
    ptr = isSmall() ? as_small : ptr;
    return ptr;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::const_pointer_t string_core<StringTrait_, Alloc_>::c_str() KS_CONST KS_NOEXCEPT {
    const_pointer_t ptr = as_ml.data_;
    ptr = isSmall() ? as_small : ptr;
    return ptr;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::swap(const string_core& rhs) KS_NOEXCEPT {
    if (isSmall()) {
        swapSmall(rhs);
    }
    swapMedium(rhs);
}


template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::pointer_t string_core<StringTrait_, Alloc_>::begin() KS_NOEXCEPT {
    if (isSmall()) {
        return as_small;
    }
    return as_ml.data_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::const_pointer_t string_core<StringTrait_, Alloc_>::begin() KS_CONST KS_NOEXCEPT {
    if (isSmall()) {
        return as_small;
    }
    return as_ml.data_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::pointer_t string_core<StringTrait_, Alloc_>::end() KS_NOEXCEPT {
    if (isSmall()) {
        return as_small + as_small[max_small_size];
    }
    return as_ml.data_ + as_ml.size_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::const_pointer_t string_core<StringTrait_, Alloc_>::end() KS_CONST KS_NOEXCEPT {
    if (isSmall()) {
        return as_small + as_small[max_small_size];
    }
    return as_ml.data_ + as_ml.size_;
}

template <typename StringTrait_, typename Alloc_>
constexpr void string_core<StringTrait_, Alloc_>::reserve(std::size_t size) KS_NOEXCEPT {
    if (isSmall()) {
        reserveSmall(size);
    } else {
        reserveMedium(size);
    }
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::push_back(char_t ch) KS_NOEXCEPT {

}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::push_back(const_pointer_t data) KS_NOEXCEPT {

}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::char_t string_core<StringTrait_, Alloc_>::pop_back() KS_NOEXCEPT {

}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::append(char_t ch) KS_NOEXCEPT {
    if (this->size() + 1 <= max_small_size) {
        appendSmall(&ch, 1);
    } else {
        appendMedium(&ch, 1);
    }
    return *this;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::append(const_pointer_t data) KS_NOEXCEPT {
    std::size_t len = string_trait::length(data);
    std::size_t new_size = this->size() + len + 1;
    std::cout << data << std::endl;
    if (new_size < max_small_size) {
        appendSmall(data, len);
    } else {
        appendMedium(data, len);
    }
    return *this;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::append(const string_core& rhs) KS_NOEXCEPT {
    std::size_t new_size = this->size() + rhs.size();
    if (new_size <= max_small_size) {
        appendSmall(rhs.begin(), rhs.size());
    } else {
        appendMedium(rhs.begin(), rhs.size());
    }
    return *this;
}

template <typename StringTrait_, typename Alloc_>
template <typename... Args>
KS_CONSTEXPR string_core<StringTrait_, Alloc_>& string_core<StringTrait_, Alloc_>::append(Args&&... args) KS_NOEXCEPT {
    (append(std::forward<Args>(args)), ...);
    return *this;
}



}

#endif //STRING_CORE_H
