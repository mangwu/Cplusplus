#include <iostream>

using namespace std;

int main(void) {
  double arr[5] = {21.1, 32.8, 23.4, 2.0, 47.4};
  double *pt = arr; // 声明一个指向数组第一个元素的指针，保存第一个元素的地址
  // 递增和递减运算符在指针中的运用
  // 优先级=>后缀运算符>前缀运算符==星号解引用运算符
  cout << "*pt = " << *pt << endl;
  cout << "*++pt = " << *++pt << endl;     // pt加1后，解引用
  cout << "++*pt = " << ++*pt << endl;     // 解引用后，将元素值+1
  cout << "(*pt)++ = " << (*pt)++ << endl; // 解引用后，返回元素值，后将元素值+1
  cout << "*pt = " << *pt << endl;
  cout << "*pt++ = " << *pt++ << endl; // pt值解引用后返回，最后将pt值+1
  cout << "*pt = " << *pt << endl;
  return 0;
};