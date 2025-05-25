#include "11.13.h" // 间接引入iostream
#include <cmath>

using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR {
// 弧度和角度的转换系数
const double Rad_to_Deg = 45.0 / atan(1.0);
// 实现Vector类的私有成员函数
// 设置矢量长度
void Vector::set_mag() {
  mag = sqrt(x * x + y * y);
}
// 设置矢量角度
void Vector::set_ang() {
  if (x == 0.0 && y == 0.0) {
    ang = 0.0;
  } else {
    ang = atan2(y, x);
  }
}

// 设置极坐标系的x值
void Vector::set_x() {
  x = mag * cos(ang);
}

// 设置极坐标系的y值
void Vector::set_y() {
  y = mag * sin(ang);
}

// 实现公共成员函数
Vector::Vector() { // 默认构造函数
  x = y = ang = mag = 0.0;
  mode = RECT;
}

// 有参数的构造函数
/**
 * @description
 * @param n1 如果form是RECT，n1表示x值，form是POL n1表示mag矢量长度
 * @param n2 如果form是RECT，n2表示y值，form是POL
 * n2表示度数，需要转换成弧度以赋值给ang
 * @param form Vector中定义的枚举Mode类型，RECT或者POL，在声明中默认为RECT
 */
Vector::Vector(double n1, double n2, Mode form) {
  mode = form;
  if (form == RECT) {
    x = n1;
    y = n2;
    set_ang();
    set_mag();
  } else if (form == POL) {
    mag = n1;
    ang = n2 / Rad_to_Deg;
    set_x();
    set_y();
  } else {
    cout << "Incorrect 3rd argument to Vector() -- ";
    cout << "Vector set to 0 and mode set to RECT\n";
    x = y = mag = ang = 0.0;
    mode = RECT;
  }
}
/**
 * @description 和有参数的构造函数相同功能，用于重置初始化矢量
 * @param n1 如果form是RECT，n1表示x值，form是POL n1表示mag矢量长度
 * @param n2 如果form是RECT，n2表示y值，form是POL
 * n2表示度数，需要转换成弧度以赋值给ang
 * @param form Vector中定义的枚举Mode类型，RECT或者POL
 */
void Vector::reset(double n1, double n2, Mode form) {
  mode = form;
  if (form == RECT) {
    x = n1;
    y = n2;
    set_ang();
    set_mag();
  } else if (form == POL) {
    mag = n1;
    ang = n2 / Rad_to_Deg;
    set_x();
    set_y();
  } else {
    cout << "Incorrect 3rd argument to Vector() -- ";
    cout << "Vector set to 0 and mode set to RECT\n";
    x = y = mag = ang = 0.0;
    mode = RECT;
  }
}

Vector::~Vector() {
  // 默认析构函数
}

// 设置成极坐标系矢量表示法
void Vector::polar_mode() {
  mode = POL;
}

// 设置成直角坐标系矢量表示法
void Vector::rect_mode() {
  mode = RECT;
}

// 重载运算符
// 重载加法运算符
Vector Vector::operator+(const Vector &b) const {
  return Vector(x + b.x, y + b.y);
}
// 重载减法运算符
Vector Vector::operator-(const Vector &b) const {
  return Vector(x - b.x, y - b.y);
}

// 重载负号运算符
Vector Vector::operator-() const {
  return Vector(-x, -y);
}

// 重载乘法运算符
Vector Vector::operator*(double n) const {
  return Vector(x * n, y * n);
}

// 重载友元的乘法运算符，以处理 n * vector的情况
Vector operator*(double n, const Vector &v) {
  // 友元函数可以返回Vector对象的私有成员
  return Vector(n * v.x, n * v.y);
}

// 重载友元的左移运算符用于打印矢量
std::ostream &operator<<(std::ostream &os, const Vector &v) {
  // 友元函数不是成员函数，不在类的作用域下，使用RECT需要域解析符
  if (v.mode == Vector::RECT) {
    os << "(x, y) = (" << v.x << ", " << v.y << ")\n";
  } else if (v.mode == Vector::POL) {
    os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_Deg << ")\n";
  } else {
    os << "Vector object mode is Valid!!!\n";
  }
  return os;
}

} // namespace VECTOR