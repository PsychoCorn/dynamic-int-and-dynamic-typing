#include "types/headers/DynamicInteger.hpp"
#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    dynamic_int n = 52;
    var test = 5, test2 = "TEST2";
    std::cout << *(test.getData().intData) << std::endl;
    test = n;
    std::cout << *(test.getData().intData) << std::endl;
    test = 5.52f;
    std::cout << *(test.getData().floatData) << std::endl;
    test = "It WORKSSS!!!";
    std::cout << *(test.getData().stringData) << std::endl;
    test = 6;
    std::cout << *(test.getData().intData) << std::endl;
    test = test2;
    test2 = 23;
    std::cout << *(test.getData().stringData) << " " << *(test2.getData().intData) << std::endl;
    return 0;
}