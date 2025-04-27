#include <iostream>

using namespace std;
// 放在main上面就不用写函数原型了
inline double square(double x) {
  return x * x;
}
int main(void) {
  double a, b;
  // 内联函数不需要跳转，直接把相关函数代码复制在这，以空间换时间
  a = square(5.0);
  cout << a << endl;
  b = square(a + 4.5);
  cout << b << endl;

  double c = 13.0;
  cout << "c = " << c << endl;
  cout << "square(c++) = " << square(c++) << endl;
  cout << "c = " << c << endl;
  return 0;
}
