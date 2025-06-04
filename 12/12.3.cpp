#include <iostream>
using std::cout;
#include "12.1.h"

void callme1(StringBad &); // 引用传递
void callme2(StringBad);   // 值传递

int main() {
  using std::endl;
  {
    cout << "Starting an inner block.\n";
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");

    cout << "headline1:" << headline1 << endl;
    cout << "headline2:" << headline2 << endl;
    cout << "headline2 address:\"" << &headline2 << "\"\n";
    cout << "sports:" << sports << endl;
    // 以上三项正常显示

    callme1(headline1); // 按引用传递，函数中不会创建临时对象
    cout << "headline1:" << headline1 << endl;
    // 按值传递，函数中会创建一个临时对象sb，
    // 函数执行完毕后sb的析构函数执行，然后被销毁
    // 因为没有重载=运算符，不同编译器会有不同的打印结果
    // 这里能正常打印说明编译器自动生成了StringBad(const StringBad&)的构造函数
    // 并且编译器会自动为你生成一个默认的赋值运算符
    // 默认的赋值运算符会对类中的每个成员变量进行逐个赋值，导致
    // sb = headline1实际上等价于 sb = StringBad(headline1);
    cout << " ---- " << endl;
    cout << "Current total strbad object:" << StringBad::getTotalStr() << endl;
    callme2(headline2);
    cout << "headline2:" << headline2 << endl;
    // 调用callme2后，num_strings的值变成2了，因为函数执行调用了一次析构函数
    cout << "Current total strbad object:" << StringBad::getTotalStr() << endl;
    cout << " ---- " << endl;
    // 用一个字符串对象初始化另一个一个对象
    cout << "Initialize one object to another:\n";
    StringBad sailor = sports;
    cout << "sailor:" << sailor << endl;
    cout << "Assign one object to another:\n";
    StringBad knot;
    knot = headline1;
    cout << "knot:" << knot << endl;
    cout << "Exiting the block.\n";
  }
  return 0;
}

void callme1(StringBad &rsb) {
  cout << "String passed by reference:\n";
  cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
  cout << "String passed by value:\n";
  cout << "    \"" << sb << "\"\n";
  cout << "    address:\"" << &sb << "\"\n";
}