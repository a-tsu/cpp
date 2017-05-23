#include "cpptoml.h"

#include <iostream>

using namespace std;

int main()
{
    auto config = cpptoml::parse_file("config.toml");
    auto value = config->get_qualified_as<string>("first.key");
    cout << "TEST";
    return 0;
}
