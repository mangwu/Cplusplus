#include <cstring> // 提供C风格的字符数组的API，例如strcpy
#include <iostream>
#include <string> // 使用string类
using namespace std;

int main(void) {
  char chars1[20];
  char chars2[20] = "jaguar";
  string str1 = "jaguar", str2 = "jaguar";
  cout << "str1 == str2 ? " << (str1 == str2) << endl; // 相等
  str1 = "panther";
  str2 = str1; // 字符串对象可以直接赋值
  cout << "str1 = " << str1 << endl;
  cout << "str2 = " << str2 << endl;
  cout << "str1 == str2 ? " << (str1 == str2) << endl; // 相等
  strcpy(chars1, chars2); // 字符数组可以通过strcpy进行赋值,是cstring提供的函数
  cout << "chars1 = " << chars1 << endl;
  cout << "chars2 = " << chars2 << endl;
  cout << "chars1 == chars2 ? " << (chars1 == chars2) << endl; // 不相等

  str1 += " paste";         // 字符串对象可以直接拼接字符
  strcat(chars1, " juice"); // 字符数组通过strcat进行拼接,也是cstring提供的函数
  cout << "str1 = " << str1 << endl;
  cout << "chars1 = " << chars1 << endl;

  const int strLen = str1.size(); // size()字符串对象获取字符串长度的方法
  const int charsLen = strlen(
      chars1); // strlen之前学过的获取字符数组中字符串长度的函数，属于cstring
  cout << "str1的长度:" << strLen << endl;
  cout << "chars1的长度:" << charsLen << endl;
  return 0;
}