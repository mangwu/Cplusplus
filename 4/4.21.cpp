#include <iostream>

using namespace std;
struct inflatable {
  char name[20];
  float volume;
  double price;
};
int main() {
  // 创建一个未命名的inflatable类型，并将其地址赋给一个inflatable*类型的指针
  inflatable *ps = new inflatable; // 这种写法和内置类型写法一致

  // 因为创建的动态结构没有具体的结构体对象，无法直接通过句点访问其内部成员
  // C++专门提供了一种运算符：箭头成员运算符，作用于指针以方便获取指针指向对象的成员
  // 指针使用->访问，对象使用句点访问
  cout << "输入 ps->name:" << endl;
  cin.get(ps->name, 20);
  cout << "输入 ps->volume" << endl;
  cin >> (*ps).volume;
  cout << "输入 ps->price" << endl;
  cin >> ps->price;
  cout << "ps->name: " << ps->name << endl;
  cout << "(*ps).name: " << (*ps).name << endl;
  cout << "ps->volume: " << ps->volume << endl;
  cout << "(*ps).volume: " << (*ps).volume << endl;
  cout << "ps->price: " << ps->price << endl;
  cout << "(*ps).price: " << (*ps).price << endl;
  delete ps;
  return 0;
};