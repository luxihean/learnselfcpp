#include <iostream>
#include <string>

using namespace std ;

bool stringequal( string str1 , string str2){
    if (str1.length() != str2.length()) return false ;
    for (int i = str1.length() - 1 ; i >= 0 ; i--){
        if (tolower(str1[i]) != tolower(str2[i])) return false ;
    }
    return true ;
}

int main(){
    string strin1 ;
    string strin2 ;
    cout << "input str1 : " << endl ;
    getline(cin , strin1) ;
    cout << "input str2 : " << endl ;
    getline(cin , strin2) ;
    cout << stringequal(strin1 ,strin2) << endl ;
    return 0 ;
}