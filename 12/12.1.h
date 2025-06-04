#include <iostream>
#ifndef TWELVE_ONE
#define TWELVE_ONE

class StringBad {
private:
  char *str;              // 指向string的指针
  int len;                // string的长度
  static int num_strings; // string_bad对象数量
public:
  StringBad(const char *s); // 构造函数
  StringBad();              // 默认构造函数
  ~StringBad();             // 析构函数
  static int getTotalStr() {
    return num_strings;
  }
  // 友元函数，重载<<
  friend std::ostream &operator<<(std::ostream &os, const StringBad &st);
};

// 上面只定义了三个特殊的成员函数，其中两个是构造函数，一个是析构函数
// 实际上C++会提供下面一些特殊的成员函数，如果没有定义的话
// 1. 默认构造函数 （主动定义了任何构造函数就不会有）
// 2. 默认析构函数 （主动定义了就不会有）
// 3. 拷贝构造函数 ，是参数为const ClassName&的构造函数（书上叫复制构造函数）
//    如果用户没有定义拷贝构造函数，编译器会生成一个按成员浅拷贝的版本
// 4. 拷贝赋值运算符，是参数为const ClassName&的赋值运算符重载(书上叫赋值运算符)
//    如果用户没有重载该运算符，编译器会生成一个按成员赋值的版本
// 5. 移动构造函数，是参数为ClassName &&的构造函数，
//    当类没有自定义移动构造函数，并且没有定义拷贝构造、
//    拷贝赋值、析构等可能冲突的函数时，编译器会生成。
// 6. 移动赋值运算符，是参数是ClassName &&的赋值运算符重载
//    同移动构造函数类似，当满足一定条件时由编译器生成

// 12.3.cpp中使用直接对象赋值的方式，会使用编译器生成的拷贝赋值运算符，
// 导致不可定义行为
#endif