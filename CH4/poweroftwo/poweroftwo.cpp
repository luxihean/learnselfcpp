#include <iostream>
#include <iomanip>

using namespace std ;

long pieceoftwo(int n , int k){
    int result = 1;
    for (int i = 0; i < k ; i++){
        result *=n;
    }
return result;
}

int main(){
    int limit;
    cout<<"input your num:" <<endl;
    cin>>(limit);
    for (int i = 0 ; i <= limit ; i++)
    {
        cout << right << setw(2) << i 
                      << setw(8) << pieceoftwo(2, i) << endl; 
    }
return 0;
}