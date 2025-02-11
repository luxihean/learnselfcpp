#include <string>
#include <stdexcept>
#include "error.h"
using namespace std;

void error(string str)
{
  throw runtime_error(str);
}

void error() {}
