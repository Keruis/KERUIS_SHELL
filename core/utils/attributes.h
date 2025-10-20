#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

namespace ks::core::utils::attributes {

#if defined(__GNUC__) || defined(__clang__)
#define KS_ALWAYS_INLINE __attribute__((always_inline)) inline
#define KS_PURE         __attribute__((pure))
#define KS_CONST        const
#elif defined(_MSC_VER)
#define KS_ALWAYS_INLINE __forceinline
#define KS_PURE
#define KS_CONST const
#else
#define KS_ALWAYS_INLINE inline
#define KS_PURE
#define KS_CONST
#endif

#define KS_CONSTEXPR constexpr
#define KS_NORETURN [[noreturn]]
#define KS_UNUSED   [[maybe_unused]]
#define KS_NOEXCEPT noexcept
#define KS_NODISCARD [[nodiscard]]

#if defined(__GNUC__) || defined(__clang__)
#define KS_LIKELY(x)   __builtin_expect(!!(x), 1)
#define KS_UNLIKELY(x) __builtin_expect(!!(x), 0)
#elif defined(_MSC_VER)
#define KS_LIKELY(x)   (x)
#define KS_UNLIKELY(x) (x)
#else
#define KS_LIKELY(x)   (x)
#define KS_UNLIKELY(x) (x)
#endif

#if __cplusplus >= 202002L
#define KS_CONSTANT_EVALUATED std::is_constant_evaluated()
#else
#define KS_CONSTANT_EVALUATED 0
#endif

}

#endif //ATTRIBUTES_H
