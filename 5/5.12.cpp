#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string word = "?ate";
  for (char ch = 'a'; word != "mate"; ch++) {
    cout << word << endl;
    word[0] = ch;
  }
  // string类型的字符串对象重载了!=和==运算符，它让字符串的比较看起来像字符串的字面量比较一样
  cout << "循环后，word = " << word << endl;
  cout << ("mate" == "mate") << endl; // 打印出1，也就是true
  return 0;
}
