#include <iostream>

using namespace std;

int main(void) {
  int donuts = 6;
  double cups = 4.5;

  cout << "cups = " << cups << endl;
  cout << "cups 变量的地址 " << (&cups) << endl; // 0x5ffec0 一个地址
  cout << "donuts = " << donuts << endl;
  cout << "donuts 变量的地址 " << (&donuts) << endl; // 0x5ffecc 一个地址

  // 符号 &是一个取地址操作符
  // int donuts = 6;语句会声明一个变量donuts，
  // 同时会在内存开辟一块4字节的空间，用于存储整型数字6
  // 这个块空间的开始字节位置会有一个标识标识它所在的地址，用16进制表示
  // C++内部会追踪该内存单元，其实体表示就是指针，指针存储值的地址
}