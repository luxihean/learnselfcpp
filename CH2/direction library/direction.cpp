#include <string>
#include <iostream>
#include "direction.h"
using namespace std;

direction leftfrom(direction dir){
    return direction ((dir + 3) % 4);
}

direction rightfrom(direction dir){
    return direction ((dir + 1) % 4);
}

string directiontostring(direction dir){
    switch (dir){
        case NORTH : return "NORTH" ;
        case EAST : return "EAST" ;
        case SOUTH : return "SOUTH" ;
        case WEST : return "WEST" ;
        default : return "???";
    }
}

int main() {
    direction current = NORTH;
    cout << "Current direction: " << directiontostring(current) << endl;

    direction left = leftfrom(current);
    cout << "Turn left: " << directiontostring(left) << endl;

    return 0;
}