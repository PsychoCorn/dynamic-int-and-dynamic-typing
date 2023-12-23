#include "types/headers/DynamicInteger.hpp"
#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    dynamic_int n = 1 << 1;
    n <<= 4;
    std::cout << n << std::endl;
    n >>= 1;
    std::cout << n << std::endl;
    return 0;
}