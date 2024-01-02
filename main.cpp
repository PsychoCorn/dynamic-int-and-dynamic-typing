#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    kondra::var n = -5;
    kondra::dynamic_int s = static_cast<kondra::dynamic_int>(n);
    std::cout << s << std::endl;
    return 0;
}
