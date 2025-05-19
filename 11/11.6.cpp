#include "11.4.h"
#include <iostream>

int main(void) {
  using std::cout;
  using std::endl;
  Time planning;
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;

  cout << "planning time = ";
  planning.Show();

  cout << "coding time = ";
  coding.Show();

  cout << "fixing time = ";
  fixing.Show();

  // 使用重载的+运算符计算coding和fixing之和
  total = coding + fixing;
  cout << "coding + fixing = ";
  total.Show();

  Time morefixing(3, 28);
  cout << "more fixing time = ";
  morefixing.Show();

  // operator+可以像之前的Sum一样使用函数调用法进行调用
  total = morefixing.operator+(total);
  cout << "morefixing.operator+(total) = ";
  total.Show();

  // 两个对象以上也可以相加
  // 由于+是从左到右结合的运算符，因此如下语句的转换步骤是：
  // 1. planning = coding.operator+(fixing + morefixing);
  // 2. planning = coding.operator+(fixing.operator+(morefixing));
  planning = coding + fixing + morefixing;
  cout << "planning = coding + fixing + morefixing = ";
  planning.Show();
  return 0;
}