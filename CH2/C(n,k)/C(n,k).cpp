#include <iostream>
using namespace std;

int fact(int i){
    int result = 1;//result值为真
    if (i == 1){
        result = 1;
    }else{
        for(int j = 1 ; j <= i ;j++){
            result *= j;
        }
    }
    return result;
}

int combination(int n ,int k){
    return fact(n) / (fact(k) * fact(n-k)); //这边分母要扩起来标出运算符优先级
}

int main(){
    while(true){
        int n = 0;
        int k = 0;
        cout << "this is a program caculate C(n, k)" << endl;
        cout << "input n : " << endl;
        cin >> n;
        cout << "input k : " << endl;
        cin >> k;
        if(n < k){
            cout << "no result" << endl;
        }else{
            cout <<"result equal to :" <<combination(n , k)<<endl;       
        }     
    }
    return 0;
}
