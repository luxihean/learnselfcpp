#include <iostream>
#include <string>
using namespace std ;

/*
string reverse(string str){
    string rev = "" ;
    for (int i = str.length()-1 ; i >= 0 ; i--){
        rev += str[i] ;
    }
    return rev ;
}

bool ispalindrome(string str){
    return str == reverse(str) ;
}

int main(){
    string str ;
    cout << "input your string : " << endl ;
    getline (cin , str) ;
    cout << ispalindrome(str) << endl ;
    return 0 ;
}
*/
//这是第一种写法，利用之前写的reverse函数
bool ispalindrome(string str){
    int n = str.length() ;
    for ( int i = 0 ; i < n/2 ; i++){
        if (str[i] != str[n - i - 1 ]) return false ; 
    }
    return true ;
}

int main(){
    string str ;
    cout << "input your string : " << endl ;
    getline (cin , str) ;
    cout << ispalindrome(str) << endl ;
    return 0 ;
}