#include <iostream>
#include <string>
#include <cctype>
using namespace std ;

bool isvowel (char ch){
    switch(ch){
        case 'A' :case 'E' :case 'I' :case 'O' :case 'U' :
        case 'a' :case 'e' :case 'i' :case 'o' :case 'u' :
        return true ;
    default:
        return false ;
    }
}

int findfirstvowel(string word){
    for (int i = 0 ; i < word.length() ; i++){
        if (isvowel (word[i])) return i ;
    }
    return -1 ;
}

string wordtopiglatin(string word){
    int fv = findfirstvowel (word) ;
    if (fv == -1){
        return word ;
    }else if (fv == 0 ){
        return word + "way" ;
    }else {
        string first = word.substr(0 , fv) ;
        string last = word.substr(fv) ;
        return last + first + "ay" ;
    }
}

string linetopiglatin(string line){
    string result ;
    int start = -1 ;
    for ( int  i = 0 ; i < line.length() ; i++ ){
        char ch = line [i] ;
        if (isalpha(ch)){
            if (start == -1) {
                start = i ;
            }
        }else{
            if (start >= 0 ){
                result += wordtopiglatin(line.substr(start , i - start)) ;
                start = -1 ;
            }               
        result += ch ;
        }
    }
    if (start >= 0 ) result += wordtopiglatin(line.substr(start)) ; 
    return result ;
}

int main(){
    cout << "This program translates English to Pig Latin." << endl ;
    string line ; 
    cout << "Enter English text: " ; 
    getline(cin, line) ;  
    string translation = linetopiglatin(line) ;
    cout << "Pig Latin output: " << translation << endl ;
    return 0 ;
}
