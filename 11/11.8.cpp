#include "11.7.h"
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

void Time::Show() const {
  std::cout << hours << " hour(s), " << minutes << " minute(s)\n";
}