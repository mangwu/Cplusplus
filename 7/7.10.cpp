#include <cstring>
#include <iostream>

using namespace std;

char *buildstr(char ch, int times);

int main(void) {
  int times; // 循环times次创建重复字符的字符串
  char ch;
  cout << "Enter a character:";
  cin >> ch;
  cout << "Enter an interger:";
  cin >> times;
  char *ps = buildstr(ch, times);
  cout << ps;
  delete[] ps;
  return 0;
}
char *buildstr(char ch, int times) {
  char *str = new char[times + 1]; // 有new记得要有对应的delete
  str[times] = '\0';               // 设置末尾元素
  while (times-- > 0) {
    str[times] = ch;
  }
  return str;
}