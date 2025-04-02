#include <iostream>

using namespace std;

int main(void) {
  cout << "输入字符表示是否进行接下来的操作?<y/n>";
  char ch;
  cin >> ch;
  bool flag = true;
  while (flag) {
    if (ch == 'y' || ch == 'Y') {
      cout << "\a开始执行操作" << endl;
      flag = false;
    } else if (ch == 'n' || ch == 'N') {
      cout << "不执行操作，再见！\n";
      flag = false;
    } else {
      cout << "输入字符表示是否进行接下来的操作?<y/n>";
      cin >> ch;
    }
  }
  return 0;
}