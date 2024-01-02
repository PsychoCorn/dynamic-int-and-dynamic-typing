#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    kondra::var n = 6.5f;
    float s = static_cast<double>(n);
    std::cout << s << std::endl;
    return 0;
}
