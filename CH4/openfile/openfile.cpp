#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

string openfile (ifstream & infile , string prompt){
    while (true){
        cout << prompt ;
        string filename ;
        getline (cin , filename) ;
        infile.open(filename) ;
        if ( ! infile.fail() ) return filename ;
        infile.clear() ;
        cerr << "UABLE TO FIND FILE" << endl ;
        if (prompt == "") prompt ="input file : " ;
    }
}

int main(){
    ifstream cinfile ;
    openfile(cinfile , "Input your file :");
    char ch ;
    while (cinfile.get (ch)){
        cout.put (ch) ; 
    }
    cinfile.close() ;
    return 0 ;
}