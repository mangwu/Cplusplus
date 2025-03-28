#include <ctime> // C风格的时间API，clock_t，clock等
#include <iostream>

using namespace std;

int main(void) {
  cout << "输入等待时间：";
  float secs;
  cin >> secs;
  // CLOCKS_PER_SEC每秒种的系统单位数,一秒有CLOCKS_PER_SEC个系统节拍,一般为1000
  clock_t delay = secs * CLOCKS_PER_SEC; // secs秒钟的总时钟节拍数

  // clock_t是ctime定义的一个long类型的别名，typedef long clock_t;
  // 这样看到clock_t就知道这个变量是一个时钟节拍，有了具体的意义

  clock_t second = CLOCKS_PER_SEC; // 每过CLOCKS_PER_SEC个节拍进行一次打印

  clock_t start = clock(); // 返回从程序开始经过的节拍数，
  // 一般是程序已运行的秒数乘以CLOCKS_PER_SEC
  cout << "当前节拍：\a" << (start = clock()) << endl;
  while (clock() - start < delay) {
    if (clock() - start > second) {
      cout << (second / CLOCKS_PER_SEC) << endl;
      second += CLOCKS_PER_SEC;
    }
  }
  cout << (second / CLOCKS_PER_SEC) << endl; // 打印最后一秒
  cout << "结束节拍：\a" << clock() << endl;
  return 0;
}