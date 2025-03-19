#include <cstring>
#include <iostream>

using namespace std;

int main(void) {
  char animal[20] = "bear"; // animal 等价于 &animal[0]
  // "wren"是一个只读的char类型字符串常量
  // 虽然cout和多数C++表达式中，char数组名，char指针以及引号括起来的字符串常量都被解释为字符串第一个字符的地址
  // 但是无法直接将C风格的字符串直接赋值给char*类型的指针，
  // 因为编译器认为你可能通过*bird修改常量的值
  const char *bird = "wren";
  // 不加const会报错： forbids converting a string constant to 'char*'
  // 加了const后，*bird会被看成一个常量，*bird不允许改变，表示bird指向的内存空间的值不能改变
  // 这样"wren"就不会改变，所以编译器能编译通过
  // 但是bird指针可以指向别的地址，因为它是一个存储地址的变量
  // bird被称为指针常量，指向不能改变的常量的内存空间
  cout << "bird = " << bird << endl;
  bird = animal;
  cout << "bird = " << bird << endl;

  char *ps; // 未被初始化
  // cout << "ps =" << ps << endl; // 会报错，使用了未初始化的指针

  cout << "输入animal:" << endl;
  cin >> animal;
  cout << "animal = " << animal << endl;
  cout << "bird = " << bird << endl;
  // cin >> ps; // 会报错，使用了一个未初始化的指针

  // 打印animal表示的字符地址
  cout << "animal数组名表示的地址：" << (int *)animal << endl;
  cout << "bird指针表示的地址：" << (int *)bird << endl;

  ps = animal;
  cout << "ps = animal; " << ps << " at " << (int *)ps << endl;

  // 让ps指向内存中新字符串空间
  ps = new char[strlen(animal) + 1];
  strcpy(ps, animal); // 复制animal的字符串到ps指向的内存字符串空间中
  cout << "ps at" << (int *)ps << endl; // 新的地址

  delete[] ps; // new开辟内存空间后，一定要释放
  return 0;
}