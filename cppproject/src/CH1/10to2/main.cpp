#include <iostream>
using namespace std;

string tentotwo(int n)
{
  int r[100]; // 用于存储二进制位
  int i = 0;  // 用于记录二进制位数
  while (n > 0)
  {
    r[i] = n % 2;
    n = n / 2;
    i++;
  }

  string binary = ""; // 用于拼接最终二进制字符串
  for (int j = i - 1; j >= 0; j--)
  { // 反向读取数组中的值
    binary += to_string(r[j]);
  }
  return binary.empty() ? "0" : binary;
}

int main()
{
  int n = 0; // 输入的十进制数
  while (1)
  {
    cout << "Enter ten:";
    cin >> n;
    if (n == -1)
    {
      break;
    }

    cout << "two output: " << tentotwo(n) << endl;
  }
  return 0;
}
