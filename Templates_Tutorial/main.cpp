

#include <type_traits>
#include <typeinfo>
#include <iostream>
/*

// general case
template <typename T>
bool Equals(T lhs, T rhs)
{
    return lhs == rhs;
}

// special case, inconvenient way
template <>
bool Equals<float>(float lhs, float rhs)
{
    return true;
}

*/

// tag dispatch
template <typename T>
bool Equals(T lhs, T rhs)
{
    return Equals(lhs, rhs, std::conditional_t<std::is_floating_point<T>::value, std::true_type, std::false_type>{});
}

template <typename T>
bool Equals(T lhs, T rhs, std::false_type)        // non floating
{
    return lhs == rhs;
}

template <typename T>
bool Equals(T lhs, T rhs, std::true_type)       // floating
{
    //imprecision handling
    return true;
}

// SFINAE -> substritution failure is not an error

int main(int argc, char const *argv[])
{
    Equals(1, 2);

    return 0;
}
