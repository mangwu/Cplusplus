#include <iostream>
using namespace std;
int main(void)
{
  char a = 'a';
  signed char b = 200; // 上溢
  short b_s = b;       // -56
  unsigned char c = 200;
  short c_s = c;                             // 200
  cout << a << "," << b << ',' << c << endl; // b c按照字符进行打印但是ascii码无对应字符
  cout << b_s << "," << c_s << endl;

  // 宽字符，处理日文汉字系统等不在ascii码中出现的字符，占用长度随系统决定
  wchar_t d = L'P';                                           // L表示后续字符为宽字符
  cout << "宽字符" << d << "的内存占用:" << sizeof d << endl; // 使用两个字节的宽字符
  // 无符号长字符，char16_t => 本质上是unsigned short int ； char32_t => 本质上是无符号unsigned long int
  char16_t g = u'q'; // 113
  char32_t h = U'\U0000222B'; // 8747
  cout << g << endl;
  cout << h << endl;
  return 0;
}