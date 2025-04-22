#include <cstring>
#include <iostream>

using namespace std;
// 计算C风格字符串中ch字符的个数
unsigned int c_int_str(const char *str, char ch);
int main(void) {
  char mmm[15] = "minimum";
  const char *wail = "ululate"; // 字面量字符串是一个只读常量，必须加const

  unsigned int ms = c_int_str(mmm, 'm');  // 获取mmm中的m字符个数
  unsigned int us = c_int_str(wail, 'u'); // 获取wail中的u字符个数
  cout << mmm << "中的\'m\'字符数有" << ms << "个" << endl;
  cout << wail << "中的\'u\'字符数有" << ms << "个" << endl;

  return 0;
}

// 计算字符个数，str指向的字符不能被改变，加const
unsigned int c_int_str(const char *str, char ch) {
  unsigned int num = 0;
  while (*str) { // *str对str地址解引用，能取出字符就能继续循环直到取到\0
    if (*str == ch)
      num++;
    str++;
  }
  return num;
}