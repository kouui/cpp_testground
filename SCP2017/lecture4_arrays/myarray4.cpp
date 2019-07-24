// myarray4.cpp

#include <iostream>

int main(int argc, char const *argv[])
{
    float a[] = {10.0, 20.0, 30.0};
    float* b = new float[3];
    float* p = a;

    for (size_t i = 0; i < 3; i++) {
        *(b+i) = a[i];
    }
    std::cout << "p = " << p << ", *p = " << *p  << '\n';
    p = p + 1;
    std::cout << "p = " << p << ", *p = " << *p  << '\n';
    std::cout << "b[]: " << *b << ", " << b[1] << ", " << *(b+2) << '\n';

    delete [] b;
    return 0;
}
