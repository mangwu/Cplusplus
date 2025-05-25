#include "11.19.h"
#include <iostream>

using namespace std;

int main(void) {
  Stonewt a = 25.2; // Stonewt(double)支持隐式转换
  Stonewt b = 64;   // 虽然explicit Stonewt(int)不支持隐式
  // 但是可以通过Stonewt(double)进行二步转换:int -> double ->Stonewt
  // 书中表示如果再增加一个非explicit的Stonewt(long)，则会有二义性，编译器会拒绝转换
  Stonewt c(21, 8); // 调用Stonewt(int, double)
  Stonewt d;        // 调用Stonewt()
  a.show_lbs();
  a.show_stn();
  b.show_lbs();
  b.show_stn();
  c.show_lbs();
  c.show_stn();
  d.show_lbs();
  d.show_stn();

  // 转换函数的使用
  double d_st = a; // 隐式转换
  cout << "Convert to double => " << d_st << " pounds\n";
  int i_st = Stonewt(9, 2.8); // 先构造临时对象，然后赋值转换
  cout << "Convert to int => " << i_st << " pounds\n";
  // 下面使用了显示的类型转换
  cout << "Convert to int => " << int(c) << " pounds\n";
  // 如果直接 cout << c; 可以吗
  // 答案是因为 Stonewt有两个转换函数，都可以被cout打印，具有二义性，所以不行
  // 如果只有doule一个转换函数，那么cout << c;可以正常运行
  // 同理 long x = c; 也因为二义性报错，因为编译器不知道用double还是int
  // 但是可以使用显示强制类型进行转换，如下
  long g = (long)c;
  cout << g << endl;

  // 使用自定义的转换函数
  i_st = c.stn_to_int();
  cout << i_st << endl;
  return 0;
}