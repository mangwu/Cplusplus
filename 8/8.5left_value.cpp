#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // 左值，右值的区分【不能】简单按照赋值语句的左右两边进行理解
  // 市面上最流行的区分方式是：能使用&取地址的值就是左值，否则为右值
  int a = 10;
  // 只有左值才有地址
  cout << &a << endl; // 变量可以取地址，是左值
  // cout << &10 << endl; // 错误，10是一个立即数，它存在的地方没有地址的概念
  // cout << &(a + 3) << endl; // 错误，a+3是一个表达式，右值
  // cout << &'a' << endl; // 错误，字符都是右值
  cout << &"abc" << endl; // 字符串是一个左值

  // 现在学习左值的目的就是
  // 【非常量】引用必须是左值，因为【非常量】引用变量必须绑定一个存在的内存空间
  int &b = a;
  cout << b << endl;
  // 但是【常量】引用可以使用右值绑定
  // C++规定，加上const后，右值放到一个临时空间，可以作为引用
  // 【常量】引用变量不能更改临时空间中的值，可以引用这个临时空间
  const int &c = 10;
  cout << c << endl;

  const int &d = a + 3;
  cout << d << endl;

  const char &e = 'a';
  cout << e << endl;

  // 特殊情况，之前说字符串是左值，为什么它不能直接赋值给string引用呢？
  // string &str = "abc"; // error: cannot bind non-const lvalue reference of
  // type 'std::string&' to an rvalue of type 'std::string'
  // 这里并不是因为"abc"不是左值，而是因为"abc"是一个常量，
  // "abc"作为常量左值，它不能被更改，所以引用它的引用变量也必须是【常量】
  const string &str = "abc"; // 这里加const的含义和前面不一样
  cout << str << endl;

  // 这些例子提示我们：在函数声明时使用const有很多好处：
  // 1. 使用const避免在函数中无意修改数据导致意想不到的错位
  // 2. 使用const既能传递const，也能接受非const 实参，否则只能接受非const数据
  // 3. 使用const引用使函数能够正确生成并使用临时变量（使用右值）

  // C++11新增了一种右值引用，这种引用可以指向右值，使用&&声明
  int &&f = 10; //
  return 0;
}