#include <iostream>     // std::cout

long frank(const unsigned int n) { return n*n; }

int main () {
    const auto nr_iterations = 1000000u;
    long a;
    for (auto n = 0u; n < nr_iterations; ++n)
    {
        a = frank(n);
    }
    std::cout << a << std::endl;
    return 0;
}
