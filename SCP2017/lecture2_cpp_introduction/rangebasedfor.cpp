// rangebasedfor.cpp
// only for >= c++11

#include <iostream>

int main()
{
    for (uint i: {1,2,3,4,5,6,7,8,9,10})
        std::cout << i << " ";

    std::cout << "\n";

    return 0;
}
