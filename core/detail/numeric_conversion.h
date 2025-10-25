#ifndef NUMERIC_CONVERSION_H
#define NUMERIC_CONVERSION_H

#include "../string/string.h"
#include "../exception/conversion_exception.h"

namespace ks::core::detail::string {

template <typename CharTy>
struct StringConverter {
private:
    using string_type = core::string::base<CharTy>;

    static string_type to_lower(const string_type &value) {
        string_type result = value;
        for (auto& c : result) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        return result;
    }

struct convert_impl {
    template <typename ConvFunc>
    static int convert_int_impl(const CharTy* value, ConvFunc conv, const char* sourceType, const char* targetType) {
        if (value == nullptr || value[0] == '\0') {
            throw exception::ConversionException(
                sourceType,
                targetType,
                std::string(value),
                exception::ConversionException::ErrorType::NullValue
            );
        }

        using EndPtrType = typename std::conditional<
            std::is_same_v<CharTy, char> ||
            std::is_same_v<CharTy, char8_t>,
            char*,
            typename std::conditional<
                std::is_same_v<CharTy, wchar_t>,
                wchar_t*,
                void*
            >::type
        >::type;
        EndPtrType end_ptr = nullptr;

        long val = conv(value, &end_ptr, 10);

        if (*end_ptr != '\0') {
            throw exception::ConversionException(
                sourceType,
                targetType,
                std::string(value),
                exception::ConversionException::ErrorType::FormatError
            );
        }

        if (val < INT_MIN) {
            throw exception::ConversionException(
                sourceType,
                targetType,
                std::string(value),
                exception::ConversionException::ErrorType::UnderflowError
            );
        }

        if (val > INT_MAX) {
            throw exception::ConversionException(
                sourceType,
                targetType,
                std::string(value),
                exception::ConversionException::ErrorType::OverflowError
            );
        }

        return static_cast<int>(val);
    }
};

public:
    static int to_int(const string_type &value) {
        auto conv = [](const char* str, char** end, int base) -> long {
            return std::strtol(str, end, base);
        };
        if constexpr (std::is_same_v<CharTy, char>) {
            return convert_impl::convert_int_impl(value.c_str(), conv, "char", "int");
        } else if constexpr (std::is_same_v<CharTy, wchar_t>) {
            auto wconv = [](const wchar_t* str, wchar_t** end, int base) -> long {
                return std::wcstol(str, end, base);
            };
            return 0;//convert_impl::convert_int_impl(value.c_str(), wconv, "wchar_t", "int");
        } else if constexpr (std::is_same_v<CharTy, char8_t>) {
            //const char* utf8_str = reinterpret_cast<const char*>(value.c_str());
            return 0;//convert_impl::convert_int_impl(utf8_str, conv, "char8_t", "int");
        } else if constexpr (std::is_same_v<CharTy, char16_t>) {
            ///
            std::string utf8_str;
            auto str_conv = [](const char* str, char** end, int base) -> long {
                return std::strtol(str, end, base);
            };
            return 0;//convert_impl::convert_int_impl(utf8_str.c_str(), str_conv, "char16_t", "int");
        } else if constexpr (std::is_same_v<CharTy, char32_t>) {
            ///
            std::string utf8_str;
            auto str_conv = [](const char* str, char** end, int base) -> long {
                return std::strtol(str, end, base);
            };
            return 0;//convert_impl::convert_int_impl(utf8_str.c_str(), str_conv, "char32_t", "int");
        } else {
            static_assert(sizeof(CharTy) == 0, "Unsupported character type");
        }
        return 0;
    }

};

}

#endif //NUMERIC_CONVERSION_H
