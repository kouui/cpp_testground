#include <iostream>
void inc(int i)
{
    i = i + 1;
}

int main()
{
    int j = 10;
    inc(j);
    std::cout << j << "\n";
    return 0;
}
