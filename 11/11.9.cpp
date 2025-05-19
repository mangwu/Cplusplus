#include "11.7.h"
#include <iostream>

int main(void) {
  using std::cout;
  Time weeding(4, 35);
  Time waxing(2, 47);
  Time total;
  Time diff;
  Time addjusted;

  cout << "weeding time = ";
  weeding.Show();

  cout << "waxing time = ";
  waxing.Show();

  cout << "total work time = ";
  total = weeding + waxing; // 使用operator+()
  total.Show();

  diff = weeding - waxing; // 使用operator-()
  cout << "weeding time - waxing time = ";
  diff.Show();

  addjusted = total * 1.5;
  addjusted.Show();

  return 0;
}