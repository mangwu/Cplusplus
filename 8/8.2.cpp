#include <iostream>

using namespace std;

int main(void) {
  int rats = 101;
  // rodents是一个rats的别名，和rats表示同一个内存空间的值
  int &rodents = rats; // 引用变量在定义时一定要初始化，它只能绑定一个变量
  int &d = rats;       // rats可以有多个别名(引用变量)

  cout << "rats = " << rats << endl;
  cout << "rodents = " << rodents << endl;

  rodents++; // 对引用变量进行的操作，相当于直接使用原始变量进行操作
  cout << "rats = " << rats << endl;
  cout << "rodents = " << rodents << endl;

  // 引用变量和原始变量使用同一个内存空间，取址是一样的
  cout << "rats adress = " << &rats << endl;
  cout << "rodents adress = " << &rodents << endl;
  return 0;
}