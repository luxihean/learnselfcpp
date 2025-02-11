#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cout << "input your number :" <<endl;
    cin >> n ;
    while (n > 1){
        if (n % 2 == 0){
            int j = 0;
            j = n/2;            
            cout << n << " is even " <<"I divided it into: " << j <<endl;
            n /= 2;
        }else{
            int j = 0;
            j = 3 * n + 1;            
            cout << n << " is odd " <<"I divided it into: " << j <<endl;
            n = j;
        }
    }
    return 0;
}