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


};

}

#endif //BASIC_STRING_H
