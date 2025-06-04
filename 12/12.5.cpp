#include "12.4.h"
#include <cstring>

int String::num_strings = 0;
String::String() {
  len = 0;
  str = new char[1];
  str[0] = '\0'; // 默认字符串是一个包含\0的字符的字符串
  num_strings++;
}

String::String(const char *s) {
  len = std::strlen(s);
  // 不能直接str = s，因为这样没有创建出属于String的字符串
  str = new char[len + 1]; // 字符串保存在堆中，对象仅保存指出字符串位置的地址
  std::strcpy(str, s);     // 复制s的内容
  num_strings++;
}

// 拷贝构造函数
String::String(const String &st) {
  num_strings++;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
}

// 析构函数
String::~String() {
  --num_strings;
  delete[] str;
}

// 重载运算符
// 拷贝赋值运算符
String &String::operator=(const String &st) {
  if (this == &st) { // 判断是否是自己赋值自己
    return *this;
  }
  delete[] str; // 删除当前对象原本指向的字符串
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  return *this;
}

// C风格赋值运算符
String &String::operator=(const char *s) {
  delete[] str;
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  return *this;
}

// 访问字符串的第i个字符，重载[]运算符
char &String::operator[](int i) {
  return str[i];
}
const char &String::operator[](int i) const {
  return str[i];
}

// 重载友元函数
bool operator<(const String &st1, const String &st2) {
  return std::strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String &st1, const String &st2) {
  return st2 < st1; // 使用上一个的重载更方便
}

bool operator==(const String &st1, const String &st2) {
  return std::strcmp(st1.str, st2.str) == 0;
}

std::ostream &operator<<(std::ostream &os, const String &st) {
  os << st.str;
  return os;
}
std::istream &operator>>(std::istream &is, String &st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is) {
    st = temp; // 使用了C风格赋值运算符重载
  }
  while (is && is.get() != '\n') {
    continue; // 消除输入存储缓冲区的数据
  }
  return is;
}
