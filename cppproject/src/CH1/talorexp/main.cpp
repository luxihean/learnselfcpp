#include <iostream>
#include <cmath>    // standard exp(x) function
using namespace std;

// 计算 exp(x) 的泰勒展开近似值
double taylor_exp(double x, int terms) {
    double result = 1.0; 
    double term = 1.0; 
    for (int n = 1; n < terms; ++n) {
        term *= x / n;  // 计算每一项 (x^n / n!)
        result += term; // 将当前项加到结果中
    }
    return result;
}

int main() {
    double x;
    int terms;

    cout << "Enter a value for x: ";
    cin >> x;

    cout << "Enter the number of terms for the Taylor series approximation: ";
    cin >> terms;

    // 计算 exp(x) 的近似值
    double approx_exp = taylor_exp(x, terms);
    // 计算标准库的 exp(x) 作为比较
    double actual_exp = exp(x);
    cout << "Taylor series approximation of exp(" << x << ") is: " << approx_exp << endl;
    cout << "Actual exp(" << x << ") using standard library: " << actual_exp << endl;
    return 0;
}
