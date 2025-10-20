#include "allocator.h"

namespace ks::core::memory::allocator {
    extern template class allocator<char>;
    extern template class allocator<wchar_t>;
    extern template class allocator<char8_t>;
    extern template class allocator<char16_t>;
    extern template class allocator<char32_t>;
}