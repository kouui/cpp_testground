// dynarr.cpp

#include <iostream>

int main(int argc, char const *argv[]) {
    int* a = new int [6];
    a[0] = 2; a[1] = 3; a[2] = 4;
    a[3] = 6; a[4] = 8; a[5] = 2;

    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += a[i];
    }

    delete [] a;

    std::cout << sum << std::endl;

    return 0;
}
