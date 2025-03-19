#include <iostream>

using namespace std;

int main(void) {
  // new会返回数组在内存空间的起始地址
  double *pd = new double[3]; // 动态数组，分配三个元素的double型数组
  // 可以把pd看作一个数组名称
  pd[0] = 0.2;
  pd[1] = 0.5;
  pd[2] = 0.8;
  cout << "pd = " << pd << endl;
  cout << "*pd = " << *pd << endl;
  cout << "pd[0] = " << pd[0] << endl;
  cout << "pd[1] = " << pd[1] << endl;
  cout << "pd[2] = " << pd[2] << endl;
  cout << "-----pd指针进行加一操作后------\n";
  pd = pd + 1; // 指针加一，表示指针地址向后移动一个double型的地址空间
  // 使用普通数组声明的数组变量不能做赋值操作，但是也可以使用+1表示下一个元素
  cout << "pd = " << pd << endl;
  cout << "*pd = " << *pd << endl;
  cout << "pd[-1] = " << pd[-1] << endl;
  cout << "pd[0] = " << pd[0] << endl;
  cout << "pd[1] = " << pd[1] << endl;
  cout << "-----pd指针进行减一还原后------\n";
  pd = pd - 1; // 指针还原，表示指针地址向前移动一个double型的地址空间
  cout << "pd = " << pd << endl;
  // 指针加一减一实际上地址值增加减少的是sizeof(double)个字节，前后相差8个字节
  delete[] pd; // 释放内存空间
  return 0;
}