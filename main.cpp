#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    dynamic_int n;
    n = 3 << dynamic_int(1);
    std::cout << n << std::endl;
    return 0;
}