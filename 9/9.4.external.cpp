#include <iostream>

using namespace std;

// 定义两个外部链接性的静态变量
int tom = 3;
int dick = 30;
// 定义一个内部链接性的静态变量
static int harry = 300;

void remote_access();

int main(void) {
  cout << "main() reports the following address.\n";
  cout << "tom = " << tom << " in address of " << &tom << endl;
  cout << "dick = " << dick << " in address of " << &dick << endl;
  cout << "harry = " << harry << " in address of " << &harry << endl;
  remote_access();
  return 0;
}