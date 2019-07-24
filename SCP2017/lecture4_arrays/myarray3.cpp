// myarray3.cpp
/*
1. c++ functions pass arguments by value, not by reference
2. but an array variable is acturally a pointer to the first element of the array.
3. thus the function taks a copy of the pointer to the array, and is able to manipulate
the original array in memory, without making a copy of it.
4. if you want your array to be protected from being modified by a function,
include the `const` flag in the function prototype
*/

#include <iostream>

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (size_t i=0; i<n; i++)
        total += arr[i];

    arr[0] += 10;
    return total;
}

int main(int argc, char const *argv[])
{
    const int arrsize = 8;
    int cookies[arrsize] = {1,2,4,8,16,32,64,128};
    int sum = sum_arr(cookies, arrsize);
    int sum2 = sum_arr(cookies, arrsize);

    std::cout << "Total cookies eaten:" << sum << '\n';
    std::cout << "Total cookies eaten:" << sum2 << '\n';
    return 0;
}
