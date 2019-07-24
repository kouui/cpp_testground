// eig1.cpp

#include <iostream>
#include <Eigen/Dense>

int main(int argc, char const *argv[])
{
    // 2x2 matrix, of type float
    Eigen::Matrix<float, 2, 2> A, B;
    A << 2, -1, -1, 3;
    B << 1, 2, 3, 1;

    std::cout << "A:     " << A <<  '\n';
    std::cout << "B:     " << B << '\n';
    std::cout << "A+B:   " << A+B << '\n';
    std::cout << "A-B:   " << A-B << '\n';
    std::cout << "1.6*A: " << 1.6*A << '\n';

    return 0;
}
