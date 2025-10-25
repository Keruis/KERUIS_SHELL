#ifndef CONVERSION_EXCEPTION_H
#define CONVERSION_EXCEPTION_H
#include <stdexcept>
#include <format>

namespace ks::core::exception {

    class ConversionException : public std::runtime_error {
    public:
        /// 错误类型枚举
        enum class ErrorType {
            FormatError,     // 格式错误
            OverflowError,   // 溢出错误
            UnderflowError,  // 下溢错误
            TypeMismatch,    // 类型不匹配
            NullValue,       // 空值错误
            InvalidArgument, // 无效参数
            CustomError      // 自定义错误
        };

        /// 构造函数
        /// @param sourceType 源类型名称
        /// @param targetType 目标类型名称
        /// @param value 转换值
        /// @param errorType 错误类型
        /// @param message 自定义错误消息
        ConversionException(
            const std::string& sourceType,
            const std::string& targetType,
            const std::string& value,
            ErrorType errorType,
            const std::string& message = ""
        ) : std::runtime_error(generateMessage(sourceType, targetType, value, errorType, message)),
            sourceType_(sourceType),
            targetType_(targetType),
            value_(value),
            errorType_(errorType),
            customMessage_(message) {}

        /// 获取源类型
        const std::string& sourceType() const noexcept { return sourceType_; }

        /// 获取目标类型
        const std::string& targetType() const noexcept { return targetType_; }

        /// 获取转换值
        const std::string& value() const noexcept { return value_; }

        /// 获取错误类型
        ErrorType errorType() const noexcept { return errorType_; }

        /// 获取自定义消息
        const std::string& customMessage() const noexcept { return customMessage_; }

    private:
        /// 生成错误消息
        static std::string generateMessage(
            const std::string& sourceType,
            const std::string& targetType,
            const std::string& value,
            ErrorType errorType,
            const std::string& customMessage
        ) {
            std::string errorTypeStr;
            switch (errorType) {
                case ErrorType::FormatError:     errorTypeStr = "FormatError"; break;
                case ErrorType::OverflowError:   errorTypeStr = "OverflowError"; break;
                case ErrorType::UnderflowError:  errorTypeStr = "UnderflowError"; break;
                case ErrorType::TypeMismatch:    errorTypeStr = "TypeMismatch"; break;
                case ErrorType::NullValue:       errorTypeStr = "NullValue"; break;
                case ErrorType::InvalidArgument: errorTypeStr = "InvalidArgument"; break;
                case ErrorType::CustomError:     errorTypeStr = "CustomError"; break;
                default:                         errorTypeStr = "未知错误";
            }

            if (!customMessage.empty()) {
                return std::format(
                    "类型转换错误: 无法将 {} 类型的值 '{}' 转换为 {} 类型 - {}: {}",
                    sourceType, value, targetType, errorTypeStr, customMessage
                );
            } else {
                return std::format(
                    "类型转换错误: 无法将 {} 类型的值 '{}' 转换为 {} 类型 - {}",
                    sourceType, value, targetType, errorTypeStr
                );
            }
        }

        std::string sourceType_;    // 源类型名称
        std::string targetType_;    // 目标类型名称
        std::string value_;         // 转换值
        ErrorType errorType_;       // 错误类型
        std::string customMessage_; // 自定义错误消息
    };

    #define TYPE_NAME(type) typeid(type).name()

    #define THROW_CONVERSION_EXCEPTION(sourceType, targetType, value, errorType, message) \
        throw ConversionException( \
            TYPE_NAME(sourceType), \
            TYPE_NAME(targetType), \
            value, \
            ConversionException::ErrorType::errorType, \
            message \
        )

}

#endif //CONVERSION_EXCEPTION_H
