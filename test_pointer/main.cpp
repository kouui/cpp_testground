#include <iostream>

void func(int &x_)  // &x_ 传入后代表x_是形参，函数内改变数值会反映到函数外； int表示x_不是指针而是变量
{
    int* x_ptr_ = &x_; // 由于x_是变量，所以要给指针赋值需要取址
    std::cout << "inside func : x = " << x_ << std::endl;
    x_ += 1; // 外头的x_的值也会变

    std::cout << "before : *x_ptr_ = " << *x_ptr_ << std::endl;
    *x_ptr_ += 1; // 先给指针取值，再改变他的数值
    std::cout << "after  : *x_ptr_ = " << *x_ptr_ << std::endl;
}

int main(int argc, char const** argv)
{
    int x = 0;

    func(x); //函数参数定义那里的&只是标明它是形参，传进参数还是像正常那样传入x，而不是指针

    std::cout << "outside func : x = " << x << std::endl;
    return 0;
}
