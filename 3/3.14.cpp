#include <iostream>
using namespace std;

int main(void)
{
  int auks, bats, coots;
  auks = 19.99 + 11.99;              // 浮点型31.98转换为整型
  cout << "auks = " << auks << endl; // 31
  bats = (int)19.99 + (int)11.99;
  cout << "bats = " << bats << endl; // 30
  coots = int(19.99) + int(11.99);
  cout << "coots = " << coots << endl; // 30

  char ch = 'E'; // 字符常量
  cout << "ch = " << ch << endl;
  cout << "int(ch) = " << int(ch) << endl;
  cout << "static_cast<int>(ch) = " << static_cast<int>(ch) << endl;
  return 0;
}