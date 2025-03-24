#include <iostream>

using namespace std;

int main(void) {
  int a = 20;
  int b = 20;
  cout << "a = " << a << " , " << "b = " << b << endl;
  // 后缀递增运算符先返回值后+1，前缀递增运算符先+1后返回值
  cout << "a++ = " << a++ << " , " << "++b = " << ++b << endl;
  cout << "a = " << a << " , " << "b = " << b << endl;

  int x = 1;
  x = 2 * x++ * (3 - ++x); // 不建议这么做，不同系统上有不同的结果
  cout << "x = " << x << endl;
  return 0;
}