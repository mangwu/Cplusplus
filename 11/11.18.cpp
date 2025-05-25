#include "11.16.h"
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
  return 0;
}