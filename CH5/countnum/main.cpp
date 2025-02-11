#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "filelib.h"
#include "vector.h"
using namespace std;

static const int COLUMNS = 7;

int main()
{
  Vector<int> lettercounts(26);
  ifstream infile;
  promptUserForFile(infile, "INPUT YOUR FILE :");
  char ch;
  while (infile.get(ch))
  {
    if (isalpha(ch))
    {
      lettercounts[toupper(ch) - 'A']++;
    }
  }
  infile.close();
  for (char ch = 'A'; ch <= 'Z'; ch++)
  {
    cout << setw(COLUMNS) << ch << "" << lettercounts[ch - 'A'] << endl;
  }
  return 0;
}