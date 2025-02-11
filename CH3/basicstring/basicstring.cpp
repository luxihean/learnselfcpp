#include <iostream>
#include <string>

using namespace std ;

string secondHalf(string str) { 
   return str.substr(str.length() / 2); 
} 

int main(){
    string str = "hello,world";
    cout << str.find('o', 5) << endl; 
    cout << secondHalf(str) << endl;
    string str2 = "hello , world";
    str2.at(0) = 'H';
    str2 += ".";
    cout << str2 << endl;
    return 0;
}