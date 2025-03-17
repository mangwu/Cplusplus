#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(void) {
  char chars1[20];
  char chars2[20] = "jaguar";
  string str1; // str1是string类的一个对象，string是std命名空间的一个类
  string str2 = "jaguar"; // C风格的字符串给str2进行赋值，str2可以看成一个字符串
  // string对象可以自发的更改字符串的长度
  cout << "chars1 = " << chars1 << endl;
  cout << "str1 = " << str1 << endl;
  cout << "chars2 = " << chars2 << endl;
  cout << "str2 = " << str2 << endl;
  cout << "str1 == chars1 ? " << (str1 == chars1) << endl; // 不相等
  cout << "str2 == chars2 ? " << (str2 == chars2) << endl; // 相等
  cout << "typeof chars1 " << typeid(chars1).name() << endl; // A20_c
  cout << "typeof str1 " << typeid(str1).name() << endl; // 包含string的字符串
  cout << "输入chars1赋值：" << endl;
  (cin >> chars1).get();
  cout << "输入str1赋值：" << endl;
  cin >> str1;
  cout << "chars1 = " << chars1 << endl;
  cout << "str1 = " << str1 << endl;
  cout << "chars2 = " << chars2 << endl;
  cout << "str2 = " << str2 << endl;
  cout << "str1 == chars1 ? " << (str1 == chars1)
       << endl; // 如果输入的字符串相同就相等
  cout << "str2 == chars2 ? " << (str2 == chars2) << endl; // 相等
  cout << "str1 == chars2 ? " << (str1 == chars2) << endl;
  return 0;
}