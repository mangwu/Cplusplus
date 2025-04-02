#include <climits>
#include <iostream>

using namespace std;

bool is_int(double);

int main(void) {
  // !取反，常用于函数返回值，也可用于表达式
  cout << "输入一个在int范围内的数：\n";
  double num;
  cin >> num;
  while (!is_int(num)) {
    cout << "输入不合法，再次输入:\n";
    cin >> num;
  }
  int val = int(num);
  cout << "You've entered the integer " << val << endl;
  return 0;
}

bool is_int(double x) {
  if (x <= INT_MAX && x >= INT_MIN) {
    return true;
  }
  return false;
}