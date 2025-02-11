#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Input your name: ";
    std::getline(std::cin, name);
    std::cout << "Welcome, " << name << "!" << std::endl;
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std ;

int main(){
    string name ;
    std :: cout << "input your name :" ;
    getline (cin , name);
    std :: cout << "welcome " << name << " !" << endl ;
    return 0 ;
}
*/
//原代码如下，想测试std命名空间和std::混用，报错无法找到string，工程中避免同时使用