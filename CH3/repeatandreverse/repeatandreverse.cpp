#include <iostream>
#include <string>

using namespace std ;

string repeatchar(int n ,char ch){
    string str = "" ;
    for (int i = 0 ; i < n ; i++){
        str += ch ;
    }
    return str ;
}

string reverse(string str){
    string rev = "" ;
    for (int i = str.length()-1 ; i >= 0 ; i--){
        rev += str[i] ;
    }
    return rev ;
}


int main(){
    string stringinput ;
    cout << "input your string :" ;
    getline(cin , stringinput) ;
    char firstChar = static_cast<char>(reverse(stringinput)[0]);
    cout << reverse(stringinput) << endl ;
    cout << repeatchar( 2 , firstChar) << endl ;
    return 0 ;
}