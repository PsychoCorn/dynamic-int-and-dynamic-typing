#include "types/headers/DynamicInteger.hpp"
#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    var test = true;
    test = toFloat(test);
    std::cout << test << std::endl;
    return 0;
}