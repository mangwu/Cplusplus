#include <iostream>

using namespace std;

int main(void) {
  char ch;
  int count = 0;
  cout << "输入字符:" << endl;
  cin.get(ch); // 尝试读取字符
  // 检测文件尾(EOF)：文本文件尾部的检查符号，用于提示文件读取完毕
  // 检查到EOF后，cin将eofbit和failbit设置成1
  // 可以通过成员函数eof()和fail()来检查eofbit或failbit是否为1
  // 文件尾条件模拟：在windows系统中，使用Ctrl+Z来模拟EOF条件
  while (cin.fail() == false) {
    cout << ch;
    ++count;
    cin.get(ch); // 读取下一个字符，这里读取到空格和回车换行符也会算字符数量
  }
  cout << endl << "读取了" << count << "个字符" << endl;
  return 0;
}