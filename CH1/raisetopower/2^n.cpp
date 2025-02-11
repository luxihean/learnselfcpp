#include <iostream>
using namespace std;

int pieceoftwo(int n , int k);

int main(){
    int limit;
    cout<<"input your num:" <<endl;
    cin>>(limit);
    for (int i = 0 ; i <= limit ; i++)
    {
        cout<<"2 to the "<< i <<"="
        << pieceoftwo(2,i) <<endl;
    }
return 0;
}

int pieceoftwo(int n , int k){
    int result = 1;
    for (int i = 0; i < k ; i++){
        result *=n;
    }
return result;
}
