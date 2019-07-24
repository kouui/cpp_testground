// autoarr.cpp

#include <iostream>

int main(int argc, char const *argv[]) {
    /* code */
    int a[6] = {2, 3, 4, 6, 8, 2};
    int sum = 0;

    for (size_t i = 0; i < 6; i++) {
        sum += a[i];
    }

    return 0;
}
