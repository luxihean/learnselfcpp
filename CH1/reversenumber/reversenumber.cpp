#include <iostream>
using namespace std;

int reversenumber(int n){
    int array[100];
    int i = 0 ;
    int sum = 0;
    while (n > 0){
        array[i] = n % 10;
        n /= 10;
        i++;
    }
    //for (int j = i - 1 ; j >= 0 ; j--){
    //    sum += array[i]*10^j;
    //}
    for (int j = 0; j < i; j++) {
    sum = sum * 10 + array[j]; 
    }
    return sum ;
}

int main(){
    int a = 0;
    while(1){
       cout << "enter a positive integer:"<<endl; 
       cin >> a;
       cout << "The reversed integer is: " << endl << reversenumber(a) << endl;
    }
    return 0 ;
    
}