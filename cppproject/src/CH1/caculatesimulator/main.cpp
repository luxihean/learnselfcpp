#include <iostream>
#include <cctype>
#include <string>
#include "stack.h"
#include "error.h"

using namespace std;
void applyoperator(char op, Stack<double> &operandstack);
void helpCommand();

double stringToReal(const string &str)
{
  return stod(str);
}

string getLine(const string &prompt)
{
  cout << prompt;
  string line;
  getline(cin, line);
  return line;
}

void applyoperator(char op, Stack<double> &operandstack)
{
  double result;
  double rhs = operandstack.pop();
  double lhs = operandstack.pop();
  switch (op)
  {
  case '+':
    result = lhs + rhs;
    break;
  case '-':
    result = lhs - rhs;
    break;
  case '*':
    result = lhs * rhs;
    break;
  case '/':
    if (rhs == 0)
      error("Division by zero.");
    result = lhs / rhs;
    break;
  default:
    error("illegal operator");
  }
  cout << result << endl;
  operandstack.push(result);
}

void helpCommand()
{
  cout << "Enter expressions in Reverse Polish Notation," << endl;
  cout << "in which operators follow the operands to which" << endl;
  cout << "they apply. Each line consists of a number, an" << endl;
  cout << "operator, or one of the following commands:" << endl;
  cout << "  Q -- Quit the program" << endl;
  cout << "  H -- Display this help message" << endl;
  cout << "  C -- Clear the calculator stack" << endl;
}

int main()
{
  cout << "RPN Calculator Simulation (type H for help)" << endl;
  Stack<double> operandStack;

  while (true)
  {
    string line = getLine("> "); 
    if (line.length() == 0)
      line = "Q";              
    char ch = toupper(line[0]); 

    if (ch == 'Q')
    { 
      break;
    }
    else if (ch == 'C')
    { 
      operandStack.clear();
    }
    else if (ch == 'H')
    { 
      helpCommand();
    }
    else if (isdigit(ch))
    {
      operandStack.push(stringToReal(line));
    }
    else
    { 
      applyoperator(ch, operandStack);
    }
  }
  return 0;
}
