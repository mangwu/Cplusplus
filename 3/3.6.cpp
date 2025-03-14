#include <iostream>
using namespace std;

int main(void)
{
  char ch = 'M'; // 字符是单引号
  int i = ch;    // 字符是特殊的整型，可以转换为int整型
  cout << ch << "的ASCII码是" << i << endl;
  // ch+1
  ch = ch + 1; // 77 + 1
  i = ch;
  cout << ch << "的ASCII码是" << i << endl;
  cout.put(ch); // cout调用put方法，用于显示字符，因为以前打印字符显示的是ASCII码，但是现在不是了，直接cout << ch 就行
  return 0;
}