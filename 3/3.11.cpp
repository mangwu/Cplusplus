#include <iostream>

using namespace std;
int main(void)
{
  cout.setf(ios_base::fixed, ios_base::floatfield);                          // 设置定点模式
  cout << "Integer division: 9 / 5 = " << 9 / 5 << endl;                     // 整型除法的结果也是整型
  cout << "floating-point division: 9.0f / 5.0f = " << 9.0f / 5.0f << endl;  // 单精度浮点相除也是浮点数
  cout << "Mixed division: 9.0 / 5 = " << 9.0 / 5 << endl;                   // 浮点数和整型相除，会把整型转换为浮点型
  cout << "double constants division: 1e7 / 9.0 = " << 1e7 / 9.0 << endl;    // 双精度浮点相除也是双精度浮点数
  cout << "float constants division: 1e7f / 9.0f = " << 1e7f / 9.0f << endl; // 精度比双精度浮点小
  return 0;
}