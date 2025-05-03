#include <iostream>

using namespace std;

template <class T1, class T2>
void ft(T1 x, T2 y) {
  // decltype能获取变量或值的类型，常在函数模板中使用，以确定不可以预知的变量类型
  decltype(x + y) xpy = x + y; // 让xpy是 x + y 表达式最终值的类型
  // typedef定义别名的方式也适合和decltype使用，以减少代码量，如下
  typedef decltype(x + y) xytype; // xytype是x+y之和的值类型
  xytype arr[10];
  xytype rxy = arr[2];
}

// 如果上面的函数模板有返回值，且返回值类型和x，y有关，那么返回值的类型如何确定？
// 不能再使用decltype(x + y)，因为编译器从左到右识别，还不知道x和y的类型
// 使用auto，auto只是一个占位符，有返回值，但是类型在后面表示，这就是后置返回类型
template <class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x + y) {
  return x + y;
}

int main(void) {

  // 用法：decltype(expression) var
  // 1. expression如果是一个没有加括号的变量，则var的类型就是变量的类型
  double x = 5.5;
  double y = 7.9;
  double &rx = x;
  const double *pd;
  decltype(x) w;      // w是一个和x相同的类型，double
  decltype(rx) u = y; // u是一个和rx相同的类型，double &
  decltype(pd) v;     // v是一个和pd相同的列相， const double *
  // 2. expression如果是一个函数调用，则var的类型和函数的返回类型相同
  long indeed(int);
  decltype(indeed(3)) m; // m是一个 long类型，indeed(3)不会实际调用
  // 3. expression是一个左值，且加了括号,那么定义的变量是其类型的引用
  double xx = 4.4;
  decltype((xx)) r2 = xx; // r2的类型是double &
  // 4. expression不是上面的三种情况，则var的类型与表达式最终的值(右值)类型相同
  int j = 3;
  int &k = j;
  int &n = j;
  decltype(j + 6) i1; // i1是一个int
  decltype(100L) i2;  // i2是一个long
  decltype(k + n) i3; // i3是一个int，k + n是两个int的和

  gt(x, y);
  return 0;
}