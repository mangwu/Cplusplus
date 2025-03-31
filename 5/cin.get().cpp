#include <iostream>

using namespace std;
int main(void) {
  // cin.get()在成功读取字符时，会返回字符对应的ASCII码的十进制数（整型）
  // 为了成功使用cin.get(),EOF会被的值在iostream中被定义为-1
  cout << "EOF = " << EOF << endl;
  int ch = cin.get();
  int count = 0;
  while (ch != EOF) {
    cout.put(ch); // 以字符形式打印
    if (ch != 10) {
      // 不打印回车换行符的ASCII码
      cout << ch;
    }
    count++;
    ch = cin.get(); // 读取下一个字符的ASCII码
  }
  cout << endl << "共" << count << "个字符" << endl;
  return 0;
}