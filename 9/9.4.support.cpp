#include <iostream>

using namespace std;

extern int tom;       // 外部变量声明
static int dick = 10; // 覆盖外部变量，定义一个内部链接的静态变量

int harry = 200; // 外部变量

void remote_access() {
  cout << "remote_access() reports the following address:\n";
  cout << "tom = " << tom << " in address of " << &tom << endl;
  cout << "dick = " << dick << " in address of " << &dick << endl;
  cout << "harry = " << harry << " in address of " << &harry << endl;
}