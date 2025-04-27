#include <iostream>

using namespace std;
// 求值的立方
double cube(double a);
// 用引用传递会影响a的实际值
double recube(double &a);
double recube2(const double &a);
int main(void) {
  double x = 3.0;
  cout << cube(x);
  cout << " cube of " << x << endl;
  cout << recube(x); // 执行后x会变成27
  cout << " recube of " << x << endl;
  cout << recube2(x); // 使用引用，但是不影响原始值
  cout << " recube of " << x << endl;

  // 使用cube能进行如下操作
  cout << cube(3.0) << endl;    // 直接传递字面值
  cout << cube(x - 15) << endl; // 表达式
  double ar[3] = {1.0, 20.0, 3.0};
  cout << cube(ar[1]) << endl; // 数组元素

  // 但是使用按引用的recube函数传递，只有ar[1]能进行传递
  // cout << recube(3.0) << endl;      // 会报错，非常量引用的初始值必须为左值
  // cout << recube(x - 15) << endl; // 会报错，非常量引用的初始值必须为左值
  int k = 15;
  // cout << recube(k) << endl; // 会报错，实际参数不正确，引用变量不接受转换
  cout << recube(ar[1]) << endl; // 数组元素

  // 使用按引用的【常量】recube2函数传递，使用右值也能传递
  // c++就是这么规定的，详见8.5left_value.cpp
  cout << recube2(3.0) << endl;    //
  cout << recube2(x - 15) << endl; //
  cout << recube2('a'); // 即使传递的实参类型不正确，【常量】引用也会做类型转换
  cout << endl;
  cout << recube2(k) << endl;
  cout << recube2(ar[2]) << endl; // 数组元素
  return 0;
}

double cube(double a) {
  a *= a * a;
  return a;
}

double recube(double &a) {
  a *= a * a; // a是外面x的引用，这样写会影响x的值
  return a;
}

double recube2(const double &a) { // 加上const保证无法修改引用变量a绑定的内存值
  return a * a * a;               // 不更改a的值以实现立法操作
}