#include <iostream>

using namespace std;
int main(void) {
  int a = 10;
  int *pt = &a;
  *pt = 20;            // a本身是个变量，没有加const，所以可以通过指针修改
  cout << *pt << endl; // 打印出10

  // 但是指针加上const，表示*pt2的值不可变，*pt2是个常量
  const int *pt2 = &a;
  // *pt2 = 30; // 如果此语句执行编译会报错
  a = 30;
  cout << *pt2 << endl;

  int b = 40;
  pt2 = &b; // pt2指针本身可以变，const只是表示*pt2不可变
  // *pt2 = 30; // 一样的，此语句执行编译会报错
  cout << *pt2 << endl;

  int c = 50;
  // 将const放在 int *后，表示pt3是一个指向c的地址常量，不可修改
  int *const pt3 = &c;
  // pt3 = &a; // 如果此语句执行编译会报错
  *pt3 = 20; // 这个时候 *pt3是可变的，因为此时的const仅表示pt3不可变
  cout << c << endl;

  int d = 60;
  // 两个const放在pt4的声明前，表示既不能修改*pt4也不能修改pt
  const int *const pt4 = &d;
  // pt4 = &a; // 如果此语句执行编译会报错
  // *pt4 = 20; // 如果此语句执行编译会报错
  cout << *pt4 << endl;

  int **pp2;
  int *p1;
  int n;

  pp2 = &p1;
  *pp2 = &n;
  *p1 = 10;
  // pp2 = 一个指向指针的指针
  // *pp2 = p1 = &n
  // **pp2 = *p1 = n

  // 这个const表示 **pp3不能修改
  const int **pp3;
  int *p3 = &n;
  // pp3 = &p3; // 此条语句错误，因为 **pp3不能修改，但是*p3可以修改

  const int *p4 = &n;
  pp3 = &p4;  // 这条语句无错误，因为*p4定义了const，*p4不可以修改

  return 0;
}