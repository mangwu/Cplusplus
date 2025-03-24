#include <iostream>

using namespace std;

int main(void) {
  int x;
  cout << "\"x = 100;\"表达式的值：";
  cout << (x = 100) << endl; // <<的优先级比=号高，所以需要使用小括号
  cout << "x = " << x << endl;
  cout << "\"x < 3;\"表达式的值：";
  cout << (x < 3) << endl;
  cout << "\"x > 3;\"表达式的值：";
  cout << (x > 3) << endl;
  // 设置输出的模式
  cout.setf(ios_base::boolalpha);
  cout << "设置输出模式为boolalpha" << endl;
  cout << "\"x < 3;\"表达式的值：";
  cout << (x < 3) << endl;
  cout << "\"x > 3;\"表达式的值：";
  cout << (x > 3) << endl;
  return 0;
}