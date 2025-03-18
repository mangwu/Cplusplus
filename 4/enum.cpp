#include <iostream>

using namespace std;

// colors是一个枚举类型，colors是枚举名
// 枚举类型会定义一些符号常量，这些常量称为枚举量
// 枚举类型声明的枚举变量只能赋值为枚举类型枚举的符号常量
enum colors {  // colors可以省略，声明一个匿名的枚举类型（不打算声明枚举变量）
  red,         // 不赋值，默认情况下会把整数值赋值给枚举量，从0开始
  orange,      // 1
  yellow,      // 2
  green,       // 3
  blue,        // 4
  violet,      // 5
  indigo,      // 6
  ultraviolet, // 7
};

int main(void) {
  colors color = blue;
  cout << "color是colors枚举类型声明的变量:" << color << endl;
  color = violet; // 枚举类型变量只能赋值为枚举类型声明的符号常量
  cout << "color = violet; " << color << endl;
  color = colors(2); // 但是整型可以通过强制类型转换成符号常量然后赋值
  cout << "color = colors(2); " << color << endl;

  // 因为枚举量是整型，所以color和枚举量可以作为数字参与到运算中，它们会被提升
  int band = color + green;
  cout << "int band = color + green; " << band << endl;

  // 可以使用赋值运算符显示枚举量的值
  // C++早期版本只能将int值赋值给枚举量，但是现在可以使用long和long long
  cout << "声明枚举量的值" << endl;
  enum rgb_colors {
    a,
    b = 256,
    red = 0xff0000,
    green = 0x00ff00,
    blue = 0x0000ff,
    other,
  };
  cout << "a:" << a << endl;         // 第一个枚举值默认为 0
  cout << "b:" << b << endl;         // 256
  cout << "red:" << red << endl;     // 16711680
  cout << "green:" << green << endl; // 65280
  cout << "blue:" << blue << endl;   // 255
  cout << "other:" << other << endl; // 256 没被初始化的枚举量比前一个枚举量大1

  // 枚举类型的取值范围，决定了枚举时能强制类型转换的整型数字范围
  enum bits {
    one = 1,
    two = 2,
    four = 4,
    eight = 8,
  };
  // 理论上，bits枚举类型的的取值范围在[0 - 15]，
  // 最大值：取枚举类型中的最大值，然后计算最高位1的位数x，
  //         最大值位2 ^ (x+1)  - 1
  // 最小值：最小值大于等于0，则最小值为0，
  //         如果小于0，则取值和最大值理论一样，-2 ^ (x+1) + 1

  bits bit = bits(6); // 在取值范围内，合法
  cout << "bits bit = bits(6); " << bit << endl;
  bit = bits(160); // 由编译器决定是否合法
  cout << "bits bit = bits(160); " << bit << endl;
  return 0;
}