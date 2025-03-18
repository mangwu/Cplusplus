#include <iostream>

using namespace std;

// 结构体可以在main函数内，也可以在外
// 这里是外部声明，所有后面的函数都可用，所以尽量放外面
// 如果在main函数内声明，只有main函数可用这个结构体
struct inflatable {
  char name[20];
  float volumn;
  double price;
};

void mail() {
  inflatable perks = {};        // 大括号内不进行初始化，默认所有字节都是0
  cout << perks.volumn << endl; // 0
}

int main(void) {
  inflatable guest = {"Glorious Gloria", 1.88, 29.99}; // name volumn price
  inflatable pal = {"Audacious Arthur", 3.12, 32.99};  // 成员列表初始化
  cout << "guest.name = " << guest.name << endl;
  cout << "guest.volumn = " << guest.volumn << endl;
  cout << "guest.price = " << guest.price << endl;

  cout << "pal.name = " << pal.name << endl;
  cout << "pal.volumn = " << pal.volumn << endl;
  cout << "pal.price = " << pal.price << endl;

  cout << "guest占用字节大小" << sizeof(guest) << endl; // 32 = 20 + 4 + 8
  cout << "pal占用字节大小" << sizeof(pal) << endl;
  cout << "结构体 inflatable 占用字节大小" << sizeof(inflatable) << endl;

  mail();
  return 0;
}