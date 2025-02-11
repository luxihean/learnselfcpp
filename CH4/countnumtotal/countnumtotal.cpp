#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

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
    int total = 0 ;
    char ch ;
    string current = "" ;

    while (cinfile.get(ch)){
        if (isdigit(ch)){
            current += ch ;
        }else{
            if (!current.empty()){
                total += stoi(current) ;
                current = "" ;
            }
        }
        cout.put (ch) ;
    }
    if (!current.empty()){
        total += stoi(current) ;
    }
    cinfile.close() ;
    cout << " / the total num is : " << total << endl ;
    return 0 ;
}