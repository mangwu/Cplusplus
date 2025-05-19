#ifndef ELEVEN_TEN_H
#define ELEVEN_TEN_H
#include <iostream>

class Time {
private:
  int hours;
  int minutes;

public:
  Time();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);
  Time operator+(const Time &t) const;
  Time operator-(const Time &t) const;
  Time operator*(const double mult) const;
  // 使用友元函数处理n * time的乘法情况
  // 友元函数不是成员函数，而是外部函数但定义在类中，表示其能访问类对象的私有成员
  // 这里不能加上const了，因为友元函数不是成员函数，
  // const只有在成员函数时表示不会修改类成员才有效
  friend Time operator*(const double mult, const Time &t);

  // void Show() const;

  // 重载 << 符号以避免每次都调用Show打印信息
  // 我们想使用cout直接打印，所以需要接受一个ostream对象，
  // 使用cout << t;时，就相当于调用 operator<<(cout, t);
  friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

#endif
