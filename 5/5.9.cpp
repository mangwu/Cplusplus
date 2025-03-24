#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string word;
  cout << "输入字符串：";
  cin >> word;
  char temp; // 暂存字符
  // 翻转字符
  for (int i = word.size() - 1, j = 0; j < i; i--, j++) {
    temp = word[i];
    word[i] = word[j];
    word[j] = temp;
  }
  cout << "翻转字符串：";
  cout << word << endl;
  // 逗号运算符用于分隔两个表达式，逗号表达式的值为第二部分的值
  int i;
  int j;
  cout << "\"i = 20, j = 2 * i;\" " << (i = 20, j = 2 * i) << endl; // 40
  // 逗号运算符的优先级很低，小于赋值运算符
  i = 17, 400;                                     // 等价于 (i = 17), 400
  cout << "i = 17, 400;" << (i = 17, 400) << endl; // 400
  cout << "i = " << i << endl;                     // 17
  // 可以使用括号
  i = (17, 400);
  cout << "i = (17, 400);" << (i = (17, 400)) << endl; // 400
  cout << "i = " << i << endl;                         // 400
  return 0;
}