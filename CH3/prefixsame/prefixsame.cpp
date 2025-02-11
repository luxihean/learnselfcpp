#include <iostream>
#include <string>

using namespace std ;

bool prefixsame(string str , string prefix){
    if (str.length() < prefix.length()) return false ;
    for (int i = 0 ; i < static_cast<int>(prefix.length()) ; i++){
        if (str[i] != prefix[i]) return false ;
    }
    return true ;
}

int main() {
    string str = "hello, world";
    cout << prefixsame(str, "hello") << endl;  // 输出: 1 (true)
    cout << prefixsame(str, "world") << endl;  // 输出: 0 (false)
    cout << prefixsame(str, "h") << endl;      // 输出: 1 (true)
    cout << prefixsame(str, "hello, world!") << endl; // 输出: 0 (false)
    return 0;
}