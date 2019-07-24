
#include "max1.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{   
    // `::max` to ensure that our `max()` template is found in the global namespace
    // not `std::max()` template in the stadard library.
    int i = 42;
    std::cout << "max(7, i):             " << ::max(7, i)   << "\n";
    
    double f1 = 3.4, f2 = 5.6;
    std::cout << "max(f1, f2):           " << ::max(f1, f2) << "\n";
    
    std::string s1 = "mathematics", s2 = "math";
    std::cout << "max(s1, s2):           " << ::max(s1, s2) << "\n";
    
    return 0;
}
