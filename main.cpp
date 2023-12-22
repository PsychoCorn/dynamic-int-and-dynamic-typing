#include "types/headers/DynamicInteger.hpp"
#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    dynamic_int n = 0;
    n += 5;
    n -= 3;
    n *= 5;
    n /= 2;
    n %= 2;
    n <<= 4;
    n >>= 1;
    --n;
    std::cout << n-- << std::endl;
    std::cout << n << std::endl;
    ++n;
    std::cout << n++ << std::endl;
    std::cout << n << std::endl;
    return 0;
}