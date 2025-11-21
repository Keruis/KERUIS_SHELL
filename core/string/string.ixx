module;

#include "types/character_type.h"

export module ks.core.string;

import ks.core.string.basic_string;
import ks.core.string.string_trait;


export namespace ks::core::string {

    template <typename CharT_>
    using base = basic::basic_string<trait::string_trait<CharT_>>;

}

export namespace ksstd {

#define X(name, type) using name = ks::core::string::base<type>;
    CHAR_TYPES_LIST
    #undef X

}
