#ifndef FIND_RESULT_H
#define FIND_RESULT_H
#include <cstddef>

namespace ks::core::string {

struct find_result {
    bool        found = false;
    std::size_t index = 0;

    explicit operator bool() const noexcept { return found; }
};

}


#endif //FIND_RESULT_H
