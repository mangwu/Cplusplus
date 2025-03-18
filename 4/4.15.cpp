#include <iostream>

using namespace std;
int main(void) {
  int updates = 6; // 开辟4个字节的内存空间
  cout << "updates = " << updates << endl;
  cout << "updates 的地址：" << (&updates) << endl;

  // 指针定义，指针变量存储一个地址，int表示它指向的值的类型是int类型
  int *p_updates = nullptr; // 定义一个指针，p_updates是一个指针变量
  cout << "p_updates = " << p_updates << endl;                         // 空指针
  cout << "p_updates == nullptr ? " << (p_updates == nullptr) << endl; // 空指针

  cout << "p_updates = & updates" << endl;
  // 使用取址操作符获取updates的地址，然后赋值给指针
  p_updates = &updates;
  // p_updates的值现在指向了updates内存空间
  cout << "p_updates = " << p_updates << endl;

  // 如果p_updates地址指向的值我们忘记了，可以通过*取值字符来获取
  cout << "*p_updates = " << (*p_updates) << endl;

  // 可以通过指针取值然后将其修改，间接改变指针指向的内存空间存储的值
  *p_updates = *p_updates + 1;
  cout << "通过指针修改内存值：*p_updates = *p_updates + 1;" << endl;
  cout << "p_updates = " << p_updates << endl;
  cout << "updates = " << updates << endl;
  return 0;
}