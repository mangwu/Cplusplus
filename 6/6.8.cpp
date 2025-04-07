#include <cctype> // C风格的字符串函数库，在C中叫ctype.h
#include <iostream>

using namespace std;

int main(void) {
  // 使用isaphla函数测试字符是否是字母
  int ch;
  cout << "输入字符串，本程序将对字符串一个个进行分析，换行键入Ctrl+Z终止：";
  cout << endl;
  int whitespace = 0; // 空格字符个数
  int digits = 0;     // 数字字符个数
  int chars = 0;      // 字母字符个数
  int punct = 0;      // 标点字符个数
  int others = 0;     // 其它字符

  ch = cin.get(); // 获取第一个字符
  while (ch != EOF) {
    // isalpha()判断字符是否是字母a-z,A-Z
    // cout.put(ch);
    if (isalpha(ch)) {
      chars++;
      // isspace()判断字符是否是标准空白字符，如空格，换页\f，换行符\n，回车\r，水平制表符\t，垂直制表符\v
    } else if (isspace(ch)) {
      whitespace++;
      // isdigit()判断字符是否是数字0-9
    } else if (isdigit(ch)) {
      digits++;
      // ispunct()判断字符是否是标点符号: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    } else if (ispunct(ch)) {
      punct++;
    } else {
      others++; // 其它字符
    }
    ch = cin.get(); // 获取下一个字符
  }
  cout << "字母字符个数" << chars << endl;
  cout << "空白字符个数" << whitespace << endl;
  cout << "数字字符个数" << digits << endl;
  cout << "标点字符个数" << punct << endl;
  cout << "其它字符个数" << others << endl;
  return 0;
}