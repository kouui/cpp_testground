// ptr.cpp

#include <iostream>

int main()
{
    int a = 7, b = 5;
    int* ptr = &a;


    a = 13;
    b = *ptr;

    std::cout << "b = " << b << "\n";

    return 0;
}
