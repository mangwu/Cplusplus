#include <iostream>

using namespace std;

int main(void) {
  int higgens = 5;
  int *pt = &higgens; // 将higgens的值取地址赋值给int * 定义的pt指针
  cout << "higgens的地址：" << pt << endl;
  cout << "pt指针指向的值：" << *pt << endl;
  cout << "pt指针的大小：" << sizeof(pt) << endl;

  // 声明指针时，指针存储的地址不能是你不能掌握的，
  // 这个地址指向的内存空间不会在声明指针时分配，
  // 所以一定要明确这个指针指向的地址，这个地址时之前计算机分配过的
  // 下面是错误代码：
  int *fellow; // 野指针
  // *fellow = 22333; // 这里要修改那个内存空间里的值呢？

  // 指针赋值时不能通过自己手打地址的方式进行，如下
  // fellow = 0x005ffebc; // 这样相当于把一个整数类型的值赋值给指针类型了

  // 可以通过强制类型转换将整型值转换为地址（但也不建议）
  fellow = (int *)0x5ffebc;
  cout << "fellow = " << fellow << endl;
  cout << "fellow的取值：" << *fellow << endl;
  return 0;
}