#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "new_allocator.h"

namespace ks::core::memory::allocator {

template <typename Tp_>
using allocator_base = new_allocator::new_allocator<Tp_>;

template <typename Tp_>
class allocator : public allocator_base<Tp_> {
public:
    using value_type = Tp_;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    allocator() { }
    allocator(const allocator& a) : allocator_base<Tp_>(a) { }
    template <typename Tp1_>
    allocator(const allocator<Tp1_>&) { }
    ~allocator() { }
    allocator& operator=(const allocator&) = default;
    static Tp_* allocate(std::size_t n) {
        if (std::is_constant_evaluated()) {
            if (__builtin_mul_overflow(n, sizeof(Tp_), &n)) {
                std::__throw_bad_array_new_length();
            }
            return static_cast<Tp_*>(operator new(n));
        }
        return allocator_base<Tp_>::allocate(n);
    }

    static void deallocate(Tp_* p, std::size_t n) {
        if (std::is_constant_evaluated()) {
            operator delete(p);
            return;
        }
        allocator_base<Tp_>::deallocate(p, n);
    }

    bool operator==(const allocator&) const {
        return true;
    }
};

template <typename Ty1_, typename Ty2_>
bool operator==(const allocator<Ty1_>&, const allocator<Ty2_>&) {
    return true;
}

template <typename Tp_>
class allocator<const Tp_> {
public:
    using value_type = Tp_;
    allocator() { }
    template <typename Up_>
    allocator(const allocator<Up_>&) { }
};

template <typename Tp_>
class allocator<volatile Tp_> {
public:
    using value_type = Tp_;
    allocator() { }
    template <typename Up_>
    allocator(const allocator<Up_>&) { }
};

template <typename Tp_>
class allocator<const volatile Tp_> {
public:
    using value_type = Tp_;
    allocator() { }
    template <typename Up_>
    allocator(const allocator<Up_>&) { }
};

template <>
class allocator<void> {
public:
    using value_type = void;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    allocator() = default;
    ~allocator() = default;

    template <typename Up_>
    allocator(const allocator<Up_>&) { }
};

extern template class allocator<char>;
extern template class allocator<wchar_t>;
extern template class allocator<char8_t>;
extern template class allocator<char16_t>;
extern template class allocator<char32_t>;

}

#endif //ALLOCATOR_H
