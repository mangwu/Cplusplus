#include <iostream>
#ifndef TWELVE_FOUR
#define TWELVE_FOUR

class String {
private:
  char *str;                    // 指向string的指针
  int len;                      // string的长度
  static int num_strings;       // string对象数量
  static const int CINLIM = 80; // cin最大的字符数量
public:
  String(const char *s);  // 构造函数
  String();               // 默认构造函数
  ~String();              // 析构函数
  String(const String &); // 拷贝构造函数
  int length() const {
    return len;
  }
  String &operator=(const String &); // 拷贝赋值运算符
  String &operator=(const char *);   // 拷贝赋值运算符
  // 重载[]运算符
  char &operator[](int i);
  const char &operator[](int i) const;
  // 友元函数，重载<<
  friend std::ostream &operator<<(std::ostream &os, const String &st);
  // 友元函数，重载>>
  friend std::istream &operator>>(std::istream &is, String &st);
  // 友元函数，重载<
  friend bool operator<(const String &st1, const String &st2);
  // 友元函数，重载>
  friend bool operator>(const String &st1, const String &st2);
  // 友元函数，重载==
  friend bool operator==(const String &st1, const String &st2);
  static int howMany() {
    return num_strings;
  }
};

#endif