#include <iostream>

void func(int &x_)
{
    int* x_ptr_ = &x_;
    std::cout << "inside func : x = " << x_ << std::endl;
    x_ += 1;

    std::cout << "before : *x_ptr_ = " << *x_ptr_ << std::endl;
    *x_ptr_ += 1;
    std::cout << "after  : *x_ptr_ = " << *x_ptr_ << std::endl;
}

int main(int argc, char const** argv)
{
    int x = 0;

    func(x);

    std::cout << "outside func : x = " << x << std::endl;
    return 0;
}
