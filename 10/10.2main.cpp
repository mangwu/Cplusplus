#include "10.2.h"
#include <iostream>

int main(void) {
  using namespace std;

  // 使用构造函数初始化，如果没有构造函数，可以直接声明，不使用后面的括号
  Stock stock1("NanoSmart", 20, 20.0);
  stock1.show();
  Stock stock2 = Stock("Boffo Objecgts", 2, 2.0); // 显示的调用非默认构造函数
  stock2.show();

  // 将对象变量进行赋值操作
  stock2 = stock1; // 同类型对象可以进行赋值操作，相当于对内存空间的copy
  stock2.show();

  // 调用构造函数，重置对象，让构造函数创建一个新的，然后重新赋值
  // 与初始化不同，这里会创建一个临时对象，被copy到stock1后然后被丢弃
  // 所有在show()之前会有析构函数调用的打印，它是那个临时对象的析构函数被调用
  stock1 = Stock("NanoSmart2", 20, 20.0);
  stock1.show();
  // 两个对象的析构函数会在main函数执行完后被执行

  Stock s3 = stock2.topval(stock1);
  s3.show();
  return 0;
}