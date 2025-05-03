#include <iostream>

using namespace std;
const int Limit = 8;
// 函数模板也需要声明
template <typename T>
void Swap(T &a, T &b);
template <typename T>
void Swap(T *a, T *b, int n);
void Show(int *p);

int main(void) {
  int i = 10;
  int j = 20;
  cout << "i, j = " << i << ", " << j << ";\n";
  cout << "使用编译器生成的交换函数交换i,j\n";
  Swap(i, j); // 执行时编译器才会生成一个int i, int j的Swap函数
  cout << "i, j = " << i << ", " << j << ";\n";
  double x = 25.5;
  double y = 65.35;
  cout << "x, y = " << x << ", " << y << ";\n";
  cout << "使用编译器生成的交换函数交换x,y\n";
  Swap(x, y); // 执行时编译器才会生成一个double x, double y的Swap函数
  cout << "x, y = " << x << ", " << y << ";\n";
  // Swap对大多数能通过=进行按值赋值的类型而言，可以用于交换两个相同类型的变量值
  // 但是对于数组而言，这个模板却有问题，因为数组无法通过=进行交换

  // 交换两个整型的数组
  int d1[Limit] = {0, 7, 0, 5, 1, 4, 6, 4};
  int d2[Limit] = {2, 4, 1, 4, 7, 8, 5, 3};
  cout << "两个原始数组d1,d2:\n";
  Show(d1);
  Show(d2);
  Swap(d1, d2, Limit); // 匹配重载的函数模板，然后生成新的交换函数
  cout << "交换后的d1,d2:\n";
  Show(d1);
  Show(d2);
  return 0;
}

// template<typename/class xxx> 告诉编译器下面开始写函数模板的定义
template <typename T>
void Swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}
// 函数模板的重载，写另外一个同名的函数模板
template <typename T>
void Swap(T *a, T *b, int n) {
  for (int i = 0; i < n; i++) {
    Swap(a[i], b[i]); // 通过前面的Swap交换两个元素的值
  }
}

void Show(int *p) {
  for (int i = 0; i < Limit; i++) {
    if (i < Limit - 1) {
      cout << p[i] << ", ";
    } else {
      cout << p[i] << "\n";
    }
  }
}