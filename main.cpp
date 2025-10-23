#include <iostream>
#include "core/string/string.h"
#include "core/types/tags.h"
#include "core/string/string_type_conversion.h"

using namespace ks::core::string::type_conversion;

int main() {
    ksstd::string a("12");
    int n = ks::core::types::tags::toInt <- a;
    std::cout << n <<std::endl;
    return 0;
}




