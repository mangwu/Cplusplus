#include <iostream>
using namespace std;

template <class T>
T lesser(T a, T b) {
  cout << "调用的是模板函数\n";
  return a < b ? a : b;
}

int lesser(int a, int b) {
  cout << "调用的是非模板函数\n";
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  return a < b ? a : b;
}

int main(void) {
  int m = 20;
  int n = -30;
  double x = 15.5;
  double y = 25.9;
  // 调用非模板的函数，因为其是int型
  cout << lesser(m, n) << endl;
  // 调用模板的函数，没有double型的普通函数，隐式的模板实例化
  cout << lesser(x, y) << endl;
  // 调用模板函数，使用<>，显式的模板实例化
  cout << lesser<>(m, n) << endl;
  // 调用模板函数，使用<int>先检查有没有显式具体化模板
  // 没有就显式的模板实例化，且指定T为int
  cout << lesser<int>(x, y) << endl;
  return 0;
}