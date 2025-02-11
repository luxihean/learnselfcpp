#ifndef _direction_h
#define _direction_h

#include <string>

enum direction {NORTH , EAST , SOUTH , WEST};

direction leftfrom(direction dir);

direction rightfrom(direction dir);

std::string directiontostring(direction dir);

#endif