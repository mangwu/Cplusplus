#include <cstring> // 提供C风格字符串的API
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  char chars[20];
  string str;
  cout << "chars未初始化时的长度：" << strlen(chars)
       << endl; // 不确定的值，strlen计算的结果和\0的位置有关
  cout << "str未初始化时的长度：" << str.size() << endl; // 0

  cout << "输入赋值给chars的字符串：" << endl;
  cin.getline(chars, 20); // 会消耗掉回车
  cout << "chars = " << chars << endl;
  cout << "输入赋值给str的字符串：" << endl;
  getline(cin, str); // getline是函数来自<string>
  cout << "str = " << str << endl;
  cout << "chars赋值后的长度：" << strlen(chars) << endl;
  cout << "str赋值后的长度：" << str.size() << endl; // 0
  
  return 0;
}