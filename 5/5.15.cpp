#include <iostream>

using namespace std;

int main(void) {
  int n;
  cout << "在1-10中进行猜数字游戏:" << endl;
  do {
    cin >> n; // 输入数字
    if (n < 7) {
      cout << "输入数字小了" << endl;
    } else if (n > 7) {
      cout << "输入数字大了" << endl;
    }
  } while (n != 7);
  cout << "7 是正确数字！";
  return 0;
}