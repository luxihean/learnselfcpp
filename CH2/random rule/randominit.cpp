#include <iostream>
#include <ctime>
using namespace std ;

void initrandomseed(){
    static bool initialized = false ;
    if(!initialized){
        srand(int( time (NULL))) ;
        initialized = true ;
    }
}