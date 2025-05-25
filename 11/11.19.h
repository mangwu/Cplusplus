#ifndef ELEVEN_NINETEEN_H
#define ELEVEN_NINETEEN_H

class Stonewt {
private:
  enum { Lbs_per_stn = 14 }; // 每英石的磅数（转换系数）
  int stones;                // 当前重量能表示的总英石数
  double pds_left;           // 减去英石后剩余的磅数
  double pounds;             // 整个磅数
public:
  Stonewt(double lbs); // 整个磅数的构造函数
  // 使用explicit关闭单参数的隐式类型转换
  explicit Stonewt(int stn);    // 整个英石的构造函数，pds_left默认为0
  Stonewt(int stn, double lbs); // 英石和剩余磅数的构造函数
  Stonewt();                    // 默认构造函数
  void show_lbs() const;
  void show_stn() const;
  // 转换函数，用于类对象到某种类型的转换，属于强制类型转换
  // 必须是类方法，不能指定返回类型，不能有参数，转换函数名称就是被转换的类型名
  operator double() const;
  operator int() const;

  // 转换函数虽然能让代码操作更顺畅，但是也带来了隐患，隐式转换让开发者不好维护
  // 原则上，请使用显示转换，所以请为转换函数加上explicit关键字
  // 加上explicit关键字的转换函数不能用于隐式的转换，只能通过double()等显示转换
  explicit operator long() const;

  // 还有一种方法可以实现类型转换，就是声明一个实现转换的自定义成员函数
  // 在需要转换时进行调用即可， 如下
  int stn_to_int() {
    return int(pounds + 0.5);
  }
};

#endif