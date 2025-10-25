#ifndef BASIC_STRING_H
#define BASIC_STRING_H

#include "string_core.h"

namespace ks::core::string::basic {

template <typename StringTrait>
class basic_string : public core::string_core<StringTrait> {
    friend class core::string_core<StringTrait>;
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
    KS_CONSTEXPR bool operator==(ArgsTy&&... args)
        KS_NOEXCEPT requires (
            requires {
                core_t::compare(std::forward<ArgsTy>(args)...);
            }
        )
    {
        return core_t::compare(std::forward<ArgsTy>(args)...);
    }

};

}

#endif //BASIC_STRING_H
