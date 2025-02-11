#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void input(double &a , double &b , double &c);
void solve(double a , double b , double c , double &x1 , double &x2);
void output(double x1 , double x2);
void error(string msg);

void input(double &a , double &b , double &c){
    cout << "this is a program solving the quadratic equation " << endl ;
    cout << "input the coefficients of the quadratic equation " << endl ;
    cout << "a : " << endl ;
    cin >> a ;
    cout << "b : " << endl ;
    cin >> b ;
    cout << "c : " << endl ;
    cin >> c ;
}

void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

void solve(double a , double b , double c , double &x1 , double &x2){
    if (a == 0) error(" the first coefficient must be nunzero .");
    double disc = b * b - 4 * a * c;
    if (disc < 0) error(" this equation has no real solvation . ");
    double sqrtdisc = sqrt(disc);
    x1 = (-b + sqrtdisc) / (2 * a);
    x2 = (-b - sqrtdisc) / (2 * a) ;
}

void output(double x1 , double x2){
    if (x1 == x2){
        cout << "the equation has the same solvation : " << x1 << endl;
    }else{
        cout << "the answers of this equation are x1 = " << x1 << " x2 = " << x2 << endl ;
    }
}

int main(){
    double a , b , c , x1 , x2;
    while (true){
        input(a , b , c);
        solve(a , b , c , x1 , x2);
        output(x1 , x2);
    }
    return 0;
}