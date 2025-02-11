#include <iostream>
#include <cstdlib>
#include "random.h"
using namespace std;

int randominteger(int low , int high){
    int r = rand()%( high - low + 1 ) + low ;
    return r ;
}
