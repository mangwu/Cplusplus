#include <cctype>
#include <iostream>

using namespace std;

int main(void) {
  const int asciiCodeSize = 128;
  // cctype的所有函数介绍：参考 https://zh.cppreference.com/w/cpp/header/cctype
  cout << "int isalnum( int ch ); " << "检查给定字符是否是字母数字字符："
       << "0-9,a-z,A-Z" << endl;
  cout << "dec\thex\tchar\t" << endl;
  for (int i = 0; i < asciiCodeSize; i++) {
    cout << dec << i << "\t0x"; // 十进制展示ascii码
    cout << hex << i << "\t";   // 十六进制展示ascii码
    cout << (char)(i >= 32 && i <= 126 ? i : ' ') << endl; // 展示可显示的字符
  }
  return 0;
}