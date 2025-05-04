#include <iostream>

using namespace std;
extern double warming; // 引用声明
void update(double dt) {
  // extern double warming;
  warming += dt;
  cout << "Update global warming is " << warming << endl;
}

void local() {
  // 局部变量
  double warming = 0.8;
  cout << "Local warming = " << warming << endl;
  // 如何使用全局的warming，使用符号::，作用域解析符，访问外部变量
  cout << "But global warming = " << ::warming << endl;
}