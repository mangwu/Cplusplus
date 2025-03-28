#include <iostream>
// 别名在前，类型在后
#define BYTE char // 预处理器定义别名，预处理器会将所有使用BYTE的地方替换为char
#define SHORT_POINTER short * // 缺点：只是简单替换，连续声明时会有问题

// 类型在前，别名在后
typedef char Byte; // typedef定义别名，更好的方式，为已有的类型建立一个新名称
typedef short *Short_pointer;

using namespace std;

int main(void) {
  BYTE b1 = 'a';
  Byte b2 = 'a';
  cout << "b1 == b2 ? " << (b1 == b2) << endl;

  short s1 = short(2);
  short s2 = short(3);
  SHORT_POINTER SP1, SP2;
  Short_pointer Sp1, Sp2;
  SP1 = &s1;
  SP2 = s2; // SP2是short类型
  Sp1 = &s1;
  Sp2 = &s2;
  cout << "SP1 = " << SP1 << endl; // s1的地址
  cout << "SP2 = " << SP2 << endl; // s2的值
  cout << "Sp1 = " << Sp1 << endl; // s1的地址
  cout << "Sp2 = " << Sp2 << endl; // s2的地址
  return 0;
}