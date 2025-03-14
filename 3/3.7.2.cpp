#include <iostream>
using namespace std;
int main(void)
{
  // 布尔类型，两个字面量 true和false
  // 非0值都可以转换为true 0值为false
  // false转换为整型为0，true转化为整型为1
  bool flag = false;
  bool flag2 = -100;
  cout << flag << endl;  // 0
  cout << flag2 << endl; // 1
  int intTrue = true;
  int intFalse = false;
  cout << intTrue << endl;  // 1
  cout << intFalse << endl; // 0
  return 0;
}