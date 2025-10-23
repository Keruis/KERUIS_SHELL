#ifndef STRING_CORE_H
#define STRING_CORE_H
#include <iostream>
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

    constexpr static std::size_t npos = static_cast<std::size_t>(-1);

protected:
    using box_t             = box::string_box<string_trait>;
    using box_t::as_ml;
    using box_t::as_small;
    using box_t::type_size;

public:
    KS_CONSTEXPR string_core& operator=(const string_core&  rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator=(string_core&&       rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator=(const_pointer_t     data) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator+(const string_core& lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator+(const string_core& lhs, const_pointer_t    rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator+(const_pointer_t    lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator+(const string_core& lhs, char_t             rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator+(char_t             lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator-(const string_core& lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator-(const string_core& lhs, const_pointer_t    rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator-(const_pointer_t    lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator-(const string_core& lhs, char_t             rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator-(char_t             lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator*(const string_core& lhs, std::size_t        rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator*(std::size_t        lhs, const string_core& rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator/(const string_core& lhs, std::size_t        rhs) KS_NOEXCEPT;
    friend KS_CONSTEXPR string_core operator/(std::size_t        lhs, const string_core& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator+=(const string_core& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator+=(const_pointer_t    rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator+=(char_t             rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator-=(const string_core& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator-=(const_pointer_t    rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator-=(char_t             rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator*=(std::size_t        rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core& operator/=(std::size_t        rhs) KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator==(const string_core& rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator!=(const string_core& rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator< (const string_core& rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator<=(const string_core& rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator> (const string_core& rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator>=(const string_core& rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator==(const_pointer_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator!=(const_pointer_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator< (const_pointer_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator<=(const_pointer_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator> (const_pointer_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator>=(const_pointer_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator==(char_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator!=(char_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator< (char_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator<=(char_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator> (char_t rhs) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR bool operator>=(char_t rhs) KS_CONST KS_NOEXCEPT;
    friend std::basic_ostream<char_t>& operator<<(std::basic_ostream<char_t>& os, const string_core& rhs) KS_NOEXCEPT;
    friend std::basic_ostream<char_t>& operator>>(std::basic_istream<char_t>& is, string_core&       rhs) KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR char_t&       operator[](std::size_t index) KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_char_t& operator[](std::size_t index) KS_CONST KS_NOEXCEPT;
    KS_NODISCARD operator const_pointer_t() KS_CONST KS_NOEXCEPT;
    KS_NODISCARD explicit operator bool() KS_CONST KS_NOEXCEPT;
    KS_NODISCARD explicit operator std::string() KS_CONST KS_NOEXCEPT;
    KS_NODISCARD explicit operator std::string_view() KS_CONST KS_NOEXCEPT;

private:
    constexpr static std::size_t last_char = sizeof(as_ml) - 1;
    constexpr static std::size_t max_small_size = last_char / type_size;

public:
    KS_CONSTEXPR string_core() KS_NOEXCEPT;
    KS_CONSTEXPR ~string_core() KS_NOEXCEPT;
    KS_CONSTEXPR string_core(string_core&& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR string_core(const string_core& rhs) KS_NOEXCEPT;
    KS_CONSTEXPR explicit string_core(const_pointer_t data) KS_NOEXCEPT;

private:
    KS_CONSTEXPR void reset() KS_NOEXCEPT;
    KS_CONSTEXPR bool isSmall() KS_NOEXCEPT;
    void setSmallSize(std::size_t s);
    void initSmall(const_pointer_t data, std::size_t size);
    void initMedium(const_pointer_t data, std::size_t size);
    void copySmall(const string_core& rhs);
    void copyMedium(const string_core& rhs);
    void reserveSmall(std::size_t size);
    void reserveMedium(std::size_t size);

public:
    KS_NODISCARD KS_CONSTEXPR std::size_t size() KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR std::size_t capacity() KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR pointer_t data() KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_pointer_t data() KS_CONST KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR pointer_t c_str() KS_NOEXCEPT;
    KS_NODISCARD KS_CONSTEXPR const_pointer_t c_str() KS_CONST KS_NOEXCEPT;
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
KS_CONSTEXPR void string_core<StringTrait_, Alloc_>::reset() noexcept {
    setSmallSize(0);
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR bool string_core<StringTrait_, Alloc_>::isSmall() KS_NOEXCEPT {
    return box_t::category() == category::Category::isSmall;
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::setSmallSize(std::size_t s) {
    as_small[max_small_size] = s;
    as_small[s] = '\0';
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
    as_ml.data_[size] = '\0';
    as_ml.size_ = size;
    as_ml.setCapacity(size + 1, category::Category::isMedium);
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
    if (size <= max_small_size) {
        return;
    }

    pointer_t mallocPtr = Alloc_t::allocate(size + 1);
    string_trait::copy(mallocPtr, as_small, static_cast<std::size_t>(as_small[max_small_size]) + 1);
    as_ml.data_ = mallocPtr;
    as_ml.setCapacity(size + 1, category::Category::isMedium);
}

template <typename StringTrait_, typename Alloc_>
void string_core<StringTrait_, Alloc_>::reserveMedium(std::size_t size) {
    if (size <= as_ml.capacity_) {
        return;
    }
    pointer_t mallocPtr = Alloc_t::allocate(size + 1);
    string_trait::copy(mallocPtr, as_ml.data_, size + 1);
    as_ml.data_ = mallocPtr;
    as_ml.setCapacity(size + 1, category::Category::isMedium);
}


template <typename StringTrait_, typename Alloc_>
KS_NODISCARD KS_CONSTEXPR std::size_t string_core<StringTrait_, Alloc_>::size() KS_NOEXCEPT {
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
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::pointer_t string_core<StringTrait_, Alloc_>::data() KS_NOEXCEPT {
    return as_ml.data_;
}

template <typename StringTrait_, typename Alloc_>
KS_CONSTEXPR typename string_core<StringTrait_, Alloc_>::const_pointer_t string_core<StringTrait_, Alloc_>::data() KS_CONST KS_NOEXCEPT {
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


}

#endif //STRING_CORE_H
