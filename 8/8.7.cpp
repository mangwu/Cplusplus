#include <iostream>
#include <string>
using namespace std;

string version1(const string &s1, const string &s2);
const string &version2(string &s1, const string &s2);
const string &version3(string &s1, const string &s2);
int main(void) {
  // 定义了三个string类的对象
  string input;
  string copy;
  string result;

  cout << "输入一个字符串：";
  getline(cin, input);
  cout << "你输入的字符串是：" << input << endl;
  copy = input;

  // 返回值是string，按值传递，result会复制一份返回值
  result = version1(input, "***"); // 字符串字面量是char *类型的
  cout << "version1(input, \"***\")的结果为" << result << endl;
  cout << "你原始的输入字符串是：" << input << endl;

  cout << "-------------------------------\n";

  result = version2(input, "###");
  cout << "version2(input, \"###\")的结果为" << result << endl;
  cout << "你原始的输入字符串是：" << input << endl;

  cout << "-------------------------------\n";
  cout << "Reseting orignal string.\n";
  input = copy;
  result = version3(input, "@@@");
  return 0;
}
// s1设置成const，不能更改s1引用的变量值，s2设置成const才能接受char *类型，
string version1(const string &s1, const string &s2) {
  string temp = s2 + s1 + s2;
  return temp;
}
// s1可以不加const，s1引用的变量的值可以被修改，s2必须设置成const
const string &version2(string &s1, const string &s2) {
  s1 = s2 + s1 + s2; // s1是外部传递的引用，这里被修改了
  return s1; // 返回s1，返回类型加const表示version2的返回值不能作为左值被修改
}
const string &version3(string &s1, const string &s2) {
  string temp = s2 + s1 + s2;
  return temp; // 直接返回temp会编译失败
  // 按引用传递会导致返回值引用temp的内存空间，
  // 但是temp在函数结束后就会被消灭，
  // 所以报错，但是version1是按值传递会被放到到一个临时空间被外部调用使用
}