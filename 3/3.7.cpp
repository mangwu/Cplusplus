#include <iostream>

using namespace std;

int main(void)
{
  cout << "\'\\a\'是震铃字符：\a\n"; // \a在有些系统上无法识别
  cout << "输入agent code:_____\b\b\b\b\b";
  long code;
  cin >> code;
  cout << "\a输入的code是" << code << "...\n";
  cout << "\acode验证通过！\n";
  return 0;
}