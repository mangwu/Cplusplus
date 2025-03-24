#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  double a1[4] = {1.2, 2.4, 3.6, 4.8};
  vector<double> a2(4);
  a2[0] = 1.0 / 3.0;
  a2[1] = 1.0 / 5.0;
  a2[2] = 1.0 / 7.0;
  a2[3] = 1.0 / 9.0;
  array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
  array<double, 4> a4;
  a4 = a3; // 标准数组不能这么干，但是对象之间可以互相拷贝
  cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
  cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
  cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
  cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

  a1[-2] = 20.2; // C++不会主动处理越界问题
  // a1是数组的第一个元素地址，那么a1-2就是地址向前移动2 (* sizeof double)位
  // 例如a1地址为0x5ffe60，那么a1-2的地址为0x5ffe50(移动了16个字节)
  cout << "a1[0]: " << a1[0] << " at " << &a1[0] << endl;
  cout << "a1[-1]: " << a1[-1] << " at " << &a1[-1] << endl;
  cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;

  // vector和array可以禁止这种不安全的越界的行为，
  // 使用它们提供的at()，用于替代[]以访问数组元素
  // at()会检查传入的索引是否合法，出现越界后会报错，但是比[]的效率低
  cout << "a2.at(2): " << a2.at(2) << " at " << &a2.at(2) << endl;
  // 会报错
  // cout << "a2.at(-2): " << a2.at(-2) << " at " << &a2.at(-2) << endl;

  return 0;
}