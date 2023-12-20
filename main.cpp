#include "types/headers/DynamicInteger.hpp"
#include "types/headers/Variable.hpp"
#include <iostream>

int main()
{
    dynamic_int n_d = -5;
    float d_s = n_d.doubleGetNumber();
    d_s += 0.5f;
    int n_s = n_d.longLongGetNumber();
    std::cout << d_s << " " << n_d.longLongGetNumber(false);
    return 0;
}