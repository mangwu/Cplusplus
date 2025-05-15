#include "stack.h"
#include <cctype>
#include <iostream>

int main(void) {
  using namespace std;
  Stack stk; // 隐式调用默认构造函数
  char ch;
  unsigned long po;
  cout << "输入A入栈\t" << "输入P出栈\t" << "输入Q退出:\n";
  while (cin >> ch && toupper(ch) != 'Q') {
    while (cin.get() != '\n') {
      continue;
    }
    // 判断是否为字母字符
    if (!isalpha(ch)) {
      cout << "\a请输入字母字符！";
      continue;
    }
    switch (ch) {
      case 'A':
      case 'a':
        cout << "输入po号入栈：";
        cin >> po;
        if (stk.isfull()) {
          cout << "栈满了！\n";
        } else {
          stk.push(po);
        }
        break;
      case 'P':
      case 'p':
        if (stk.isempty()) {
          cout << "栈为空！\n";
        } else {
          stk.pop(po);
          cout << "Po #" << po << " popped\n";
        }
        break;
      default:
        cout << "输入指令不对！\a\n";
        break;
    }
    cout << "输入A入栈\t" << "输入P出栈\t" << "输入Q退出:\n";
  }
  return 0;
}