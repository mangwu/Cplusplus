#include <iostream>

using namespace std;

const int ArSize = 10;

void strcount(const char *str);

int main(void) {
  char input[ArSize];
  char next;
  cout << "输入一行字符串:\n";
  cin.get(input, ArSize);
  while (cin) {
    cin.get(next);
    while (next != '\n') { // 清除缓冲区中超过ArSize的无效字符
      cin.get(next);
    }
    strcount(input);
    cout << "输入下一行(输入空行退出)\n";
    cin.get(input, ArSize); // 读取到空行会让while(cin)退出
  }
  cout << "Bye.\n";
  return 0;
}

void strcount(const char *str) {
  // 只会在第一个调用函数时被初始化，并且在代码块不处于活动状态时仍然存在
  static int total = 0; // 静态局部变量
  int count = 0;        // 自动变量
  cout << "\"" << str << "\" contains ";
  while (*str++) {
    count++;
  }
  total += count;
  cout << count << " characters\n";
  cout << total << " characters total\n";
}