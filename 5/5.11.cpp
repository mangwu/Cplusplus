#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  char word[5] = "?ate";
  for (char ch = 'a'; strcmp(word, "mate"); ch++) {
    cout << word << endl;
    word[0] = ch;
  }
  // strcmp(a, b) 是cstring提供的方法，用于判断两个字符串是否相同
  // 判断的字符串可以是string, char数组，字符串字面量
  // 返回值0=>相等，1=>b的字典序优先于a(a排在b之后)，-1=>a的字典序优先于b(a排在b之前)
  // 使用 == 是无法判断 三者是否相等的，
  // 因为C++大部分情况下，char数组，字符串字面量表示的都是首字母地址
  cout << "word is " << word << endl;

  cout.setf(ios_base::boolalpha);
  cout << "word == \"mate\" ? " << (word == "mate") << endl;
  cout << "strcmp(word, \"mate\") ? " << strcmp(word, "aate") << endl;
  return 0;
}
