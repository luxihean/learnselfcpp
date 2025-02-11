# include <iostream>
using namespace std ;

int  roundtonearint (double x){
    int j ;
    for (int i = 0 ; i < x ; i++){
        if( x - i < 0.5){
            j = i ;
        }else{
            j = i + 1 ;
        }
    }
    return j ;
}

int main(){
    double x ;
    while (true) {
    cout << "this is a program determine the near int :" << endl ;
    cin >> x ;
    cout << "the nearst int is : " << roundtonearint (x) << endl ;        
    }
    return 0 ;
}

/*
///也可以使用static_cast<int>直接取整，可以减少一定的编译时间
#include <iostream>
using namespace std;

int roundtonearint(double x) {
    double fractional_part = x - static_cast<int>(x);
    if (fractional_part < 0.5) {
        return static_cast<int>(x);
    } else {
        return static_cast<int>(x) + 1;
    }
}

int main() {
    double x;
    cout << "This is a program to determine the nearest integer:" << endl;
    cout << "Please enter a decimal number: ";
    cin >> x;
    cout << "The nearest integer is: " << roundtonearint(x) << endl;
    return 0;
}
*/