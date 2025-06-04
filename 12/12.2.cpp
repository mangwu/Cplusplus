#include "12.1.h"
#include <cstring>

using std::cout;

// 初始化静态成员，注意初始化时指明了类型，但是没有关键字static
int StringBad::num_strings = 0;

// 定义成员函数
StringBad::StringBad(const char *s) {
  len = std::strlen(s);
  // 不能直接str = s，因为这样没有创建出属于StringBad的字符串
  str = new char[len + 1]; // 字符串保存在堆中，对象仅保存指出字符串位置的地址
  std::strcpy(str, s);     // 复制s的内容
  num_strings++;
  // 字符串构建数量信息
  cout << num_strings << ": \"" << str << "\" object created\n";
}

// 默认构造函数
StringBad::StringBad() {
  len = 4;
  str = new char[len];
  std::strcpy(str, "C++"); // 使用"C++"构造默认字符串
  num_strings++;
  cout << num_strings << ": \"" << str << "\" object created\n";
}

// 需要定义析构函数，因为使用了new
StringBad::~StringBad() {
  cout << "\"" << str << "\" object deleted,";
  --num_strings;
  cout << num_strings << " left\n";
  delete[] str;
}

// 重载运算符
std::ostream &operator<<(std::ostream &os, const StringBad &st) {
  os << st.str;
  return os;
}
