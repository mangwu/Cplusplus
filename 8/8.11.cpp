#include <iostream>

using namespace std;
// 函数模板：让编译器根据我们定义的模板，生成特征标不同的函数
// 函数模板：不是一个函数，是一个模板，它只是告诉编译器如何声明一个函数
// 函数模板也需要声明
template <typename T>
void Swap(T &a, T &b);
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

// Swap对大多数能通过=进行按值赋值的类型而言，可以用于交换两个相同类型的变量值
// 但是对于数组而言，这个模板却有问题，因为数组无法通过=进行交换