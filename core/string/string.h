#ifndef STRING_H
#define STRING_H

#include "basic_string.h"
#include "string_trait.h"

namespace ks::core::string {

template <typename CharT_>
using base = basic::basic_string<trait::string_trait<CharT_>>;

}

namespace ksstd {

#define X(name, type) using name = ks::core::string::base<type>;
CHAR_TYPES_LIST
#undef X

}

#endif //STRING_H
