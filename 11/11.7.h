#ifndef ELEVEN_SEVEN_H
#define ELEVEN_SEVEN_H

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
  // Time Sum(const Time &t) const;
  // 使用重载加法运算符，将Sum()名称改为operator+()即可
  Time operator+(const Time &t) const;
  Time operator-(const Time &t) const;
  Time operator*(const double mult) const;
  void Show() const;
};

#endif
