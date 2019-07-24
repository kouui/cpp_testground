#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*******************************************************************************
拉格朗日插值
*******************************************************************************/

template<class T>
T interp_lagrange(const vector<T>& vx, const vector<T>& vy, T x){
    int n = vx.size() - 1;
    T y = 0;
    for (int i=0; i<=n; i++) {
        T temp = 1;
        for (int j=0; j<=n; j++)
            if (j != i) temp *= (x-vx[j])/(vx[i]-vx[j]);
        y += temp * vy[i];
    }

    return y;
}

void test_lagrange(){
    const int n = 4;
    vector<float> px(n);
    vector<float> py(n);
    for (int i=0; i<n; i++) {
        px[i] = 1+i/4.0;
        py[i] = exp(px[i]);
    }
    float x = 1.4;

    cout.precision(20);
    cout << "Error (lagrange): " << abs(interp_lagrange(px, py, x) - exp(x)) << endl;
}
/*******************************************************************************
牛顿插值
*******************************************************************************/
template<class T>
T interp_newton(const vector<T>& vx, const vector<T>& vy, T x) {
    vector<T> b = vy;
    int n = vx.size()-1;

    //求牛顿系数
    for (int j=1; j<=n; j++)
        for (int i=n; i>=j; i--)
            b[i] = (b[i]-b[i-1])/(vx[i]-vx[i-j]);

    //计算插值多项式在点x的值
    T u = b[n];
    for (int i=n-1; i>=0; i--) u = b[i] + (x-vx[i])*u;

    return u;
}

void test_newton(){
    const int n = 4;
    vector<float> px(n);
    vector<float> py(n);
    for (int i=0; i<n; i++) {
        px[i] = 1+i/4.0;
        py[i] = exp(px[i]);
    }
    float x = 1.4;

    cout.precision(20);
    cout << "Error (newton)  : " << abs(interp_newton(px, py, x) - exp(x)) << endl;
}

/*******************************************************************************
main
*******************************************************************************/

int main()
{
    test_lagrange();
    test_newton();
}
