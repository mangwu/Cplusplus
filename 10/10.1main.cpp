#include "10.1.h"
#include <iostream>

int main(void) {
  using namespace std;
  // 使用构造函数初始化，如果没有构造函数，可以直接声明，不使用后面的括号
  Stock fluffy_the_cat("NanoSmart", 20, 12.50);
  // 初始化
  // fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
  fluffy_the_cat.show();
  // 买股票
  fluffy_the_cat.bug(15, 18.125);
  fluffy_the_cat.show();
  // 卖出股票
  fluffy_the_cat.sell(400, 20);
  fluffy_the_cat.show();
  // 买入股票
  fluffy_the_cat.bug(300000, 40.125);
  fluffy_the_cat.show();
  // 卖出股票
  fluffy_the_cat.sell(300000, 0.125);
  fluffy_the_cat.show();
  return 0;
}