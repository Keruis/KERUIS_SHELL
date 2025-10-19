#ifndef NEW_ALLOCATOR_H
#define NEW_ALLOCATOR_H

#include <cstddef>
#include <new>
#include <type_traits>
#include <bits/functexcept.h>

namespace ks::core::memory::new_allocator {

template <typename Tp_>
class new_allocator {
public:
    using value_type        = Tp_;
    using pointer           = Tp_*;
    using const_pointer     = const Tp_*;
    using reference         = Tp_&;
    using const_reference   = const Tp_&;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;

    template <typename Other_>
    using rebind = new_allocator<Other_>;

    new_allocator() { }
    new_allocator(const new_allocator&) { }
    template <typename Ty1_>
    new_allocator(const new_allocator<Ty1_>&) { }

    new_allocator& operator=(const new_allocator&) = default;

    static pointer allocate(size_type n, const void* = 0) {
        static_assert(sizeof(Tp_) != 0, "cannot allocate incomplete types");

        if (n == 0) return nullptr;

        if (n > max_size()) {
            if (n > (static_cast<std::size_t>(-1) / sizeof(Tp_))) {
                std::__throw_bad_array_new_length();
            }
            std::__throw_bad_alloc();
        }

        if (alignof(Tp_) > 16) {
            const auto al = static_cast<std::align_val_t>(alignof(Tp_));
            return static_cast<pointer>(operator new(n * sizeof(Tp_), al));
        }
        return static_cast<pointer>(operator new(n * sizeof(Tp_)));
    }

    static void deallocate(pointer p, const size_type n) {
        if (alignof(Tp_) > 16) {
            operator delete(p, n * sizeof(Tp_), static_cast<std::align_val_t>(alignof(Tp_)));
        }
    }

    template <typename Up_>
    friend bool operator==(const new_allocator&, const new_allocator<Up_>&) {
        return true;
    }


public:
    static size_type max_size() {
        return static_cast<std::size_t>(0x7fffffffffffffffLL) / sizeof(Tp_);
    }
};

}

#endif //NEW_ALLOCATOR_H
