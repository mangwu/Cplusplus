#ifndef ELEVEN_SIXTEEN_H
#define ELEVEN_SIXTEEN_H

class Stonewt {
private:
  enum { Lbs_per_stn = 14 }; // 每英石的磅数（转换系数）
  int stones;                // 当前重量能表示的总英石数
  double pds_left;           // 减去英石后剩余的磅数
  double pounds;             // 整个磅数
public:
  Stonewt(double lbs);          // 整个磅数的构造函数
  // 使用explicit关闭单参数的隐式类型转换
  explicit Stonewt(int stn);    // 整个英石的构造函数，pds_left默认为0
  Stonewt(int stn, double lbs); // 英石和剩余磅数的构造函数
  Stonewt();                    // 默认构造函数
  void show_lbs() const;
  void show_stn() const;
};

#endif