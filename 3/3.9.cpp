#include <iostream>
using namespace std;

int main()
{
  float a = 2.34e22f;
  float b = a + 1.0F;
  // 默认模式输出
  cout << "a =" << a << endl;
  cout << "b - a =" << b - a << endl;
  return 0;
}