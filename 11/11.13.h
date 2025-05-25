#ifndef ELEVEN_THIRTEEN_H
#define ELEVEN_THIRTEEN_H

#include <iostream>

namespace VECTOR {
class Vector {
public:
  enum Mode { RECT, POL }; // 不属于类，表示两种矢量表示法
private:
  double x;   // 矢量水平值
  double y;   // 矢量竖直值
  double mag; // 矢量长度
  double ang; // 矢量角度
  Mode mode;  // RECT 或者 POL
  // 下面私有方法以设置私有成员
  void set_mag();
  void set_ang();
  void set_x();
  void set_y();

public:
  Vector();                                           // 默认构造函数
  Vector(double n1, double n2, Mode form = RECT);     // 自定义构造函数
  void reset(double n1, double n2, Mode form = RECT); //
  ~Vector();                                          // 析构函数
  double xval() const {
    return x;
  } // 内联函数，返回x的值
  double yval() const {
    return y;
  } // 内联函数，返回y的值
  double magval() const {
    return mag;
  } // 内联函数，返回magnitude
  double angval() const {
    return ang;
  } // 内联函数，返回angle
  void polar_mode(); // 设置成POL mode
  void rect_mode();  // 设置成RECT mode
  // 重载运算符
  Vector operator+(const Vector &b) const;
  Vector operator-(const Vector &b) const;
  Vector operator-() const;
  Vector operator*(double n) const;
  // 友元函数
  friend Vector operator*(double n, const Vector &a);
  friend std::ostream &operator<<(std::ostream &os, const Vector &v);
};
} // namespace VECTOR

#endif