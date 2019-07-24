
#include <iostream>
#include "constant.h"


int main (int argc, char *argv[])
{
    constexpr double a = math::Pi;
    std::cout << "value a = " << a << '\n';
}
