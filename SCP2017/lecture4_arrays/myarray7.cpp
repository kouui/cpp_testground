// myarray4.cpp
// allocate_matrix2 must be in contiguous layout


#include <iostream>

float** allocate_matrix1(const int n, const int m)
{
    float** a = new float* [n];
    for (size_t i = 0; i < n; i++)
    {
        a[i] = new float [m];
    }
    return a;
}

float** allocate_matrix2(const int n, const int m)
{
    float** a = new float* [n];
    a[0] = new float[n * m];
    for (size_t i = 0; i < n; i++)
    {
        a[i] = &a[0][i * m];
    }
    return a;
}

void print_matrix(float** a, const int n, const int m)
{
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cout << a[i][j] << ", ";
        }
        std::cout << '\n';
    }
}

void delete_matrix1(float** a, const int n)
{
    for (size_t i = 0; i < n; i++) delete [] a[i];
    delete [] a;
}

void delete_matrix2(float** a, const int n)
{
    delete [] a[0];
    delete [] a;
}

int main(int argc, char const *argv[])
{
    float** b = allocate_matrix2(3, 4);

    print_matrix(b, 3, 4);

    delete_matrix2(b, 3);

    return 0;
}
