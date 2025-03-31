#include <iostream>

using namespace std;

int main(void) {
  double prices[5] = {4.99, 54.22, 24.11, 14.33, 52.98};
  for (double x : prices) {
    cout << x << endl;
  }
  cout << "打8折" << endl;
  // &表示x是一个引用变量
  for (double &x : prices) {
    x = x * 0.8;
  }
  for (double x : prices) {
    cout << x << endl;
  }
  return 0;
}