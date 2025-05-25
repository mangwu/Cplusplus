#include "11.19.h"
#include <iostream>

using std::cout;

// 接受一个参数的构造函数与改参数相同类型的值转换为类提供了蓝图
// 即可以通过Stonewt s = 25.2; // 进行赋值，调用下面这个构造函数
// 这个过程是隐式转换的，可以用explict在声明中关闭这种自动特性
// 但是仍然可以通过(Stonewt)(25.2)这种强制类型转换的方式进行类型转换
Stonewt::Stonewt(double lbs) {
  cout << "Stonewt(double)\n";
  stones = int(lbs) / Lbs_per_stn; // 强制类型转换lbs
  // 巧妙利用强制类型转换获取剩余的磅数
  pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
  pounds = lbs;
}

// 关闭 Stonewt s = 25; // 这种类型转换
Stonewt::Stonewt(int stn) {
  cout << "Stonewt(int)\n";
  stones = stn;
  pds_left = 0;
  pounds = stn * Lbs_per_stn;
}

Stonewt::Stonewt(int stn, double lbs) {
  cout << "Stonewt(int, double)\n";
  if (lbs >= Lbs_per_stn) {
    cout << "非法lbs值，将构造0重量Stonewt对象\n";
    stones = pds_left = pounds = 0;
    return;
  }
  stones = stn;
  pds_left = lbs;
  pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() {
  cout << "Stonewt()\n";
  stones = pds_left = pounds = 0;
}

void Stonewt::show_stn() const {
  cout << stones << " 英石，" << pds_left << " 磅\n";
}
void Stonewt::show_lbs() const {
  cout << pounds << " 磅\n";
}

// 实现转换函数
// 转换函数虽然没有定义返回类型，但是要返回和转换函数名称相同类型的值
Stonewt::operator double() const {
  return pounds;
}
Stonewt::operator int() const {
  // 四舍五入
  return int(pounds + 0.5);
}

// long转换函数是explicit的，但是定义时不用加
Stonewt::operator long() const {
  // 四舍五入
  return long(pounds + 0.5);
}
