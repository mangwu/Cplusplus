#include <iostream>
#include <string>

// cv限定符
// const volatile
// const用于声明定义一个常量，该常量的内存空间的只不能被修改
// volatile声明的变量，用于改善编译器对该变量的优化能力：
//    例如，编译器发现几条语句多次使用一个变量，那么它会把这个变量的值缓存到寄存器
//    ，方便读取，但是这种优化有时候可能会导致读取到错误的值，因为其他程序或硬盘
//    能修改其中的值（指针可以指向硬盘的某个位置）
//    将变量声明为volatile则避免了编译器的这种优化

// volatile还有其他作用，书中只是其中一种

using namespace std;
// mutable关键字：用在结构或类的成员上，用于指出
// 即使结构对象或类对象声明为const，其声明为mutable的成员也是可以修改的
struct Data {
  string name;          // name不可修改
  mutable int accesses; // 可以修改accesses
};

// const 关键字会影响全局静态变量的链接性，const全局变量的链接性是内部的
const int finger = 10; // 相当于static const int fingers = 10;外部无法引用
// 如果我要使用外部定义的常量，如何引用呢？
// 解决方案是：在头文件中定义一些const常量，然后在需要用的地方引入头文件即可
// 因为const常量的链接性是内部的，在多个文件中引入头文件也不会冲突

// 为什么const常量不能是外部的？
// 如果它是外部的，在其他文件引入需要使用extern关键字引入，
// 这个时候就会出现未初始化错误，如下
extern const int other; // const声明的变量必须被初始化，与extern冲突

// 如何定义外部的const变量,使用extern关键字，
// 并且只在一个文件中进行初始化，其他文件通过extern const int states引入
extern const int states = 50; // 外部链接性的const变量

int main(void) {
  volatile int a = 5; // 避免编译器优化，将a的值缓存到寄存器中
  int b = a + 1;
  int c = a + 2;
  const Data veep = {"Clayasg Aastc", 0};
  veep.accesses++; // 允许
  cout << veep.accesses << endl;
  // veep.name = "New Name"; // 不允许，编译器会报错
  return 0;
}