#include <iostream>

using namespace std;

int main(void) {
  char ch;
  int count = 0;
  cout << "输入字符，输入#字符表示退出输入:\n";
  cin >> ch; // 获取第一个字符
  // 在键盘输入时可以敲击一些字符
  // 敲击回车键后，字符序列存入缓存区，cin才开始读取一个个字符
  // cin读取到空格字符，会直接跳过，直接读取下一个字符
  while (ch != '#') {
    cout << ch;
    ++count;
    cin >> ch;
  }
  char other[10];
  cin >> other;
  cout << endl << count << "个字符\n";
  cout << "其它字符:" << other << endl;
  return 0;
}