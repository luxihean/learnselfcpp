#include <iostream>
using namespace std;

int permutations(int n ,int k){
    int result = 1;
    for (int j = n ; j > n - k ; j--){
        result *= j ;
    }
    return result ;
}

int main(){
    while(true){
        int n = 0;
        int k = 0;
        cout << "this is a program caculate P(n, k)" << endl;
        cout << "input n : " << endl;
        cin >> n;
        cout << "input k : " << endl;
        cin >> k;
        if(n < k){
            cout << "no result" << endl;
        }else{
            cout <<"result equal to :" <<permutations(n , k)<<endl;       
        }     
    }
    return 0;
}