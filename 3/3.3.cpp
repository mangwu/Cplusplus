#include <iostream>

using namespace std;

int main()
{
  int a = 42;   // 十进制
  int b = 0x42; // 十六进制
  int c = 042;  // 八进制
  cout << "十进制：" << a << "\n";
  cout << "十六进制：" << b << "\n"; // cout的输出按照十进制进行输出整数
  cout << "八进制：" << c << "\n";

  cout << "---按照进制打印---" << endl; // hex oct dec位于std中，尽量不要当作变量名
  cout << hex;                          // 不打印，但是会改变数字的显示方式
  cout << b << " 0x42" << endl;
  cout << oct; //
  cout << c << " 042" << endl;
  cout << a << "(42按照八进制显示)" << endl;
  return 0;
}