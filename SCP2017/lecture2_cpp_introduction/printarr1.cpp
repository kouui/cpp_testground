// printarr1.cpp

#include <iostream>

void printarr(int n, int b[]){
    for (int i=0; i<n; i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {

    int n = 10;
    int b[n];

    for (int i=0; i<n; i++)
        b[i] = i*i;

    printarr(n, b);

    return 0;
}
