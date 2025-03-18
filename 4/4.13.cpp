#include <cstring>
#include <iostream>

using namespace std;

struct inflatable {
  char name[20];
  float volume;
  double price;
};

// 共用体，和结构体的区别在于它能存储不同的数据类型，但是只能同时存储其中一种类型
// 如下一个商品的id可以是数字，也可以是字符串，这种情况下可以如下定义
// 这个共用体就可以声明一个要么表示数字，要么表示字符串的id类型
union id {
  long id_num;
  char id_char[20];
};

int main(void) {
  // 结构数组，赋值时使用嵌套成员列表赋值
  inflatable guests[2] = {{"mangwu", 2.55, 62.99}, {"wumang", 45.22, 41.88}};
  cout << guests[0].name << " " << guests[1].name << endl;
  cout << guests[0].volume << " " << guests[1].volume << endl;
  cout << guests[0].price << " " << guests[1].price << endl;

  // 共用体
  id id_value;
  strcpy(id_value.id_char, "123");
  cout << "共用体id声明的id_value，将id_char赋值为\"123\"" << endl;
  cout << "id_value.id_char = " << id_value.id_char << endl; // 123
  cout << "不可预知：id_value.id_num = " << id_value.id_num
       << endl; // 不可预知的
  cout << "共用体id声明的id_value，将id_num赋值为数字123" << endl;
  id_value.id_num = 123;
  cout << "不可预知的：id_value.id_char = " << id_value.id_char
       << endl;                                            // 不可预知的
  cout << "id_value.id_num = " << id_value.id_num << endl; // 123
  cout << "共用体是共用存储大小的，union id对象的大小：" << sizeof(id_value)
       << "字节" << endl;
  return 0;
}