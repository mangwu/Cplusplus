#include "11.10.h"
#include <iostream>

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

// 重载Time类型的加法运算符
Time Time::operator+(const Time &t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

// 重载Time类型的减法运算符
Time Time::operator-(const Time &t) const {
  Time diff;
  int tot1, tot2;
  tot1 = t.minutes + 60 * t.hours;
  tot2 = minutes + 60 * hours;
  diff.minutes = (tot2 - tot1) % 60;
  diff.hours = (tot2 - tot1) / 60;
  return diff;
}

// 重载Time类型的乘法运算符
Time Time::operator*(const double mult) const {
  Time result;
  long totalMinutes = hours * mult * 60 + minutes * mult;
  result.hours = totalMinutes / 60;
  result.minutes = totalMinutes % 60;
  return result;
}

// 友元函数的定义：因为不是成员函数，所以不需要使用Time::
// 友元函数定义时不需要使用friend关键字
Time operator*(const double mult, const Time &t) {
  Time result;
  // 因为是Time的友元函数，所以Time对象在此函数作用域类可以直接访问私有成员
  long totalMinutes = t.hours * mult * 60 + t.minutes * mult;
  result.hours = totalMinutes / 60;
  result.minutes = totalMinutes % 60;
  // 实际上可以通过交换操作数顺序，直接调用上方的乘法重载运算符
  // 这样做没有使用t的私有成员，它将这个友元函数编写成了非友元函数
  // 但是这个取巧的版本作为友元函数也好，因为它作为正式类的接口更有意义，
  // 并且后续维护这个运算符重载时需要使用t的私有成员，也好直接使用
  // return t * mult;
  return result;
}

// ostream引用能指向ostream对象和ofstream对象
std::ostream &operator<<(std::ostream &os, const Time &t) {
  os << t.hours << " hour(s), " << t.minutes << " minute(s)\n";
  return os;
}

// void Time::Show() const {
//   std::cout << hours << " hour(s), " << minutes << " minute(s)\n";
// }