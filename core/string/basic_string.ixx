module;

#include <memory>

#include "../utils/attributes.h"

export module ks.core.string.basic_string;

import ks.core.string.string_core;

export namespace ks::core::string::basic {

    template <typename StringTrait>
    class basic_string : public core::string_core<StringTrait> {
        using core_t = core::string_core<StringTrait>;

    public:
        using string_trait = StringTrait;
        using core_t::core_t;

        template <typename... ArgsTy>
        KS_CONSTEXPR basic_string operator+(ArgsTy&&... args)
            noexcept requires (
                requires {
                    basic_string { *this, std::forward<ArgsTy>(args)... };
                }
            )
        {
            return { *this, std::forward<ArgsTy>(args)... };
        }

        template <typename... ArgsTy>
        KS_CONSTEXPR basic_string& operator+=(ArgsTy&&... args) KS_NOEXCEPT {
            return this->append(std::forward<ArgsTy>(args)...);
        }

        template <typename... ArgsTy>
        KS_CONSTEXPR basic_string& operator=(ArgsTy&&... args)
            noexcept requires (
                requires {
                    core_t::assignment(std::forward<ArgsTy>(args)...);
                }
            )
        {
            core_t::assignment(std::forward<ArgsTy>(args)...);
            return *this;
        }

        template <typename... ArgsTy>
        KS_CONSTEXPR bool operator==(ArgsTy&&... args)
            KS_NOEXCEPT requires (
                requires {
                    core_t::compare(std::forward<ArgsTy>(args)...);
                }
            )
        {
            return core_t::compare(std::forward<ArgsTy>(args)...);
        }

        template <typename... Args>
        KS_CONSTEXPR basic_string& append(Args&&... args) KS_NOEXCEPT {
            (core_t::append(std::forward<Args>(args)), ...);
            return *this;
        }

    };
    // if constexpr (sizeof...(Args) > 1) {
    //     std::size_t added_size = (core_t::get_addend_length(args) + ... + 1);
    //     this->reserve(this->size() + added_size);
    //     std::cout << "f" << std::endl;
    // } else
    // {
    //     std::cout << "size : " << (core_t::get_addend_length(args), ...) << std::endl;
    //     std::cout << "" << std::endl;
    // }
}