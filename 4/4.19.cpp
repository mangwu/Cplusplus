#include <iostream>

using namespace std;

int main(void) {
  double wages[3] = {1000.0, 2000.0, 3000.0};
  short stacks[3] = {3, 2, 1};

  double *pw = wages; // 数组名指向的是数组的首地址
  cout << "pw = " << pw << endl;
  cout << "*pw = " << *pw << endl;
  pw = pw + 1; // pw加一
  cout << "----pw + 1后----\n";
  cout << "pw = " << pw << endl;
  cout << "*pw = " << *pw << endl;
  cout << "sizeof wages = " << sizeof wages << endl;
  cout << "sizeof pw = " << sizeof pw << endl;

  cout << endl;
  cout << "----定义一个ps指针为&stacks[0]----\n";
  short *ps = &stacks[0]; // 数组第一个元素的取地址也是数组的首地址
  cout << "ps = " << ps << endl;
  cout << "*ps = " << *ps << endl;
  cout << "ps == stacks ? " << (ps == stacks) << endl;
  cout << "*stacks = " << *stacks << endl;
  cout << "*(stacks + 1)= " << *(stacks + 1) << endl; // 数组名可以当作指针来用

  ps = ps + 1; // ps加一
  cout << "----ps + 1后----\n";
  cout << "ps = " << ps << endl;
  cout << "*ps = " << *ps << endl;
  cout << "ps - stacks = " << (ps - stacks) << endl;
  cout << "sizeof stacks = " << sizeof stacks << endl;
  cout << "sizeof ps = " << sizeof ps << endl;

  // 数组名被解释为第一个数组元素的地址，对数组名取地址得到的是整个数组的地址
  cout << "数组名stacks是数组第一个元素的地址：\n";
  cout << "stacks = " << stacks << " &stacks[0] = " << &stacks[0] << endl;
  cout << "&stacks = " << &stacks << endl;
  cout << "stacks == &stacks[0] ? " << (stacks == &stacks[0]) << endl;
  // cout << "stacks == &stacks ? " << (stacks == &stacks) << endl;
  // 会报错，'short int*' and 'short int (*)[3]'无法比较

  short(*pas)[3] = &stacks;
  // 注意括号，把小括号拿出来*pas定义了一个指针，它指向的内存空间类型为short[3]
  // 如果去掉括号，就定义了一个指针数组
  cout << "pas =" << pas << endl;
  return 0;
}