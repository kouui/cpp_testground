//
//  main.cpp
//  using_eigen
//
//  Created by on 2018/11/6.
//  Copyright @2018 kouui. All rights reserved.
//

#include <Eigen/Dense>
#include <iostream>

int main()
{
    // Dynamic
    // X : unknown size, resizable
    // d : double
    Eigen::MatrixXd m;

    // fixed Sized Matrix
    Eigen::Matrix3d f;

    f << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    f = Eigen::Matrix3d::Constant(1.0);

    m = Eigen::MatrixXd::Constant(5, 5, 1.0);

    std::cout << m << "\n";
}
