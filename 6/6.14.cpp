#include <iostream>
const int MAX = 5;
using namespace std;

int main(void) {
  int golf[MAX];
  cout << "输入5个高尔夫得分\n"; // 保证输入5个数
  for (int i = 0; i < MAX; i++) {
    cout << "第#" << (i + 1) << "回合的得分：";
    while (!(cin >> golf[i])) {   // 处理没有正确输入导致没有成功读取的情况
      cin.clear();                // 重置cin，以开启cin的捕获
      while (cin.get() != '\n') { // 清除缓冲区的错误输入，
        continue;                 // 因为错误输入的最后一位一定是'\n'
      }
      cout << "非法输入\a,请输入一个数字:"; // 如果下次输入为数字，则会跳出循环
    }
  }
  double total = 0.0;
  for (int score : golf) {
    total += score;
  }
  cout << "5个高尔夫回合的平均得分为：" << total / MAX << endl;
  return 0;
}