#include <iostream>

using namespace std;

int main(void) {
  char ch;
  cout << "键入字符，然后程序打印:\n";
  cin.get(ch);
  while (!cin.fail()) {
    if (ch == '\n') {
      cout << ch; // enter键
    } else {
      cout << ++ch; // 打印ASCII码的下一位
    }
    cin.get(ch);
  }
  return 0;
}