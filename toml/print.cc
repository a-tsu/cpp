#include <iostream>
#include "cpptoml.h"

int main()
{
    auto config = cpptoml::parse_file("config.toml");
    std::string a = "テスト\n";
    std::cout << a;
    return 0;
}
