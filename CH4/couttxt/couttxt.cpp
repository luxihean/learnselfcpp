/*
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std ;

int main(){
    ifstream infile ;
    infile.open( " you.txt ") ;
    if(!infile){
        cerr << "ERROR" << endl ;
        return 1 ;
    }

    char ch ;
    while (infile.get(ch)){
        cout << ch ;
    }
    
    infile.close();
    return 0 ;

}
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#define getcwd _getcwd
#else
#endif

using namespace std;

int main() {
    // 获取当前工作目录
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        cout << "Current working directory: " << cwd << endl;
    } else {
        cerr << "Error: Could not retrieve current working directory." << endl;
        return 1;
    }

    // 打开文件
    string you = "you.txt";
    ifstream infile(you);
    if (!infile) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    char ch;
    while (infile.get(ch)) {
        cout << ch;
    }

    infile.close();
    return 0;
}
