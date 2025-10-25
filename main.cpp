#include <iostream>
#include <string>
#include "core/string/string.h"
#include "core/types/tags.h"
#include "core/string/string_type_conversion.h"

using namespace ks::core::string::type_conversion;

int main() {
    ksstd::string a("124567");
    ksstd::string b("124567");
    auto c = a + b + "sss";
    int n = ks::core::types::tags::toInt <- a;
    std::cout << c.c_str() <<std::endl;
    return 0;
}




