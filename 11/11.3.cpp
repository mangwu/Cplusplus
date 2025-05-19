#include "11.1.h"
#include <iostream>

int main(void) {
  using std::cout;
  using std::endl;
  Time planning; // 调用默认构造函数
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;

  cout << "planing time =\t";
  planning.Show();

  cout << "coding time =\t";
  coding.Show();

  cout << "fixing time =\t";
  fixing.Show();

  total = coding.Sum(fixing);

  cout << "coding.Sum(fixing) =\t";
  total.Show();

  return 0;
}