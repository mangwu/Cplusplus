#include <iostream>

using namespace std;

struct antarctica_year_end {
  int year;
};

int main(void) {
  antarctica_year_end s01, s02, s03;
  s01.year = 1998;                // 使用对象访问成员使用句点运算符
  antarctica_year_end *pa = &s02; // 创建结构体指针
  pa->year = 1999;                // 使用指针访问指向结构体对象的成员使用箭头符

  antarctica_year_end trio[3]; // 结构体数组
  trio[0].year = 2003;         // 等价于  (*(trio + 0)).year = 2003
  cout << trio->year << endl;  // trio相当于指向第一个结构体的指针

  // 定义了一个结构体指针数组，*arp[i]是常量，所以要初始赋值
  const antarctica_year_end *arp[3] = {&s01, &s02, &s03};
  cout << arp[1]->year << endl; // arp[i]是一个指针，需要使用箭头符访问对象成员

  const antarctica_year_end **ppa = arp; // ppa是一个指向结构体指针类型的指针
  cout << (*ppa)->year << endl;          // 就是arp[0]->year

  auto ppb = arp;                     // auto的用法，根据arp的类型推断ppb的类型
  cout << (*(ppb + 1))->year << endl; // 相当于arp[1]->year
  return 0;
}