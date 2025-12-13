module;

#include <stdint.h>

export module ks.core.constexpr_utils.compile_time_seed;

import ks.core.constexpr_utils.hash;

export consteval uint32_t compile_time_seed() {
    constexpr auto t = __TIME__;
    constexpr auto d = __DATE__;

    return hash_constexpr(t, sizeof(t))
         ^ hash_constexpr(d, sizeof(d))
         ^ __LINE__ * 2654435761u
         ^ __COUNTER__ * 40503;
}