#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std ;

int detnum (string prompt){
    string line ;
    int value ;
    while (true){
        cout << prompt ;
        getline (cin , line) ;
        istringstream stream(line) ;
        stream >> value >> ws ;
        if (stream.eof() && !stream.fail()) break ;
        cout << "ERROR ! make sure your input is a num and input again " << endl ;
    }
    return value;
}

//<cctype>中的isdigit函数也可实现类似功能

int pieceoftwo(int n , int k){
    int result = 1;
    for (int i = 0; i < k ; i++){
        result *=n;
    }
return result;
}

int main(){
    int limit = detnum ("input your num : ");
    for (int i = 0 ; i <= limit ; i++)
    {
        cout<<"2 to the "<< i <<"="
        << pieceoftwo(2,i) <<endl;
    }
return 0;
}
