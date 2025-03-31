#include <iostream>

using namespace std;

int main(void) {
  char ch;
  int count = 0;
  cout << "输入字符:" << endl;
  // cin.get(ch); // 尝试读取字符，第1，2种写法中需要
  // 检测文件尾(EOF)：文本文件尾部的检查符号，用于提示文件读取完毕
  // 检查到EOF后，cin将eofbit和failbit设置成1
  // 可以通过成员函数eof()和fail()来检查eofbit或failbit是否为1
  // 文件尾条件模拟：在windows系统中，使用Ctrl+Z来模拟EOF条件（在行首并打回车）

  // 第一种写法：使用==符号判断布尔值
  // while (cin.fail() == false) {
  // 第二种写法：可简化成!cin.fail()，因为cin.fail()返回一个布尔值
  // while (!cin.fail()) {
  // 第三种写法：cin.get(ch)本身返回一个cin，而cin在while添加中会被转换为布尔值，表示是否读取成功
  while (cin.get(ch)) {
    cout << ch;
    ++count;
    // cin.get(ch);
    // 读取下一个字符，这里读取到空格和回车换行符也会算字符数量，第三种写法不需要
  }
  cout << endl << "读取了" << count << "个字符" << endl;
  // 运行刀这里，eofbit和failbit已经设置为1，
  // 为了后续继续读取输入，可以使用clear()清楚
  cin.clear();
  cout << "cin.clear()后，cin.fail() :" << cin.fail() << endl;

  return 0;
}