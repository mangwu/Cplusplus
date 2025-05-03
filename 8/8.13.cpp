#include <iostream>

using namespace std;

struct job {
  char name[40];
  double salary;
  int floor;
};

void Swap(int &a, int &b);
template <typename T>
void Swap(T &a, T &b);
// 显式具体化模板也要声明
template <>
void Swap<job>(job &j1, job &j2); // <job>可以省略

void Show(const job &j);

int main(void) {
  cout.precision(2);                      // 设置cout的输出精度
  cout.setf(ios::fixed, ios::floatfield); // 定点模式
  int i = 20;
  int j = 10;
  cout << "i, j = " << i << ", " << j << ";\n";
  Swap(i, j);
  cout << "i, j = " << i << ", " << j << ";\n";
  job sue = {"Susan Yaffe", 73000.60, 7};
  job sidney = {"Sideney Taffee", 78060.72, 9};
  cout << "sue和sidney了两个job对象交换前的数据:\n";
  Show(sue);
  Show(sidney);
  cout << "sue和sidney交换以后的数据:\n";
  // 如何使用通用模板中会让job对象中的成员整个进行交换
  // 需求：只交换salary和floor，不交换名称，可以声明定义job的显式具体化模板
  Swap(sue, sidney);
  Show(sue);
  Show(sidney);
  return 0;
}

// 非模板函数 -> 函数定义
void Swap(int &a, int &b) {
  cout << "使用非模板函数交换int型数\n";
  int temp;
  temp = a;
  a = b;
  b = temp;
}

// 函数模板 -> 对大多数类型的生成对于函数的通用化模板
template <typename T>
void Swap(T &a, T &b) {
  cout << "函数模板:使用编译器生成的交换函数交换\n";
  T temp;
  temp = a;
  a = b;
  b = temp;
}

// 显式具体化模板->它也是一个模板，但是是针对一个具体的类型进行特殊化的定义
template <>
void Swap<job>(job &j1, job &j2) { // <job>可以省略
  // 对于job类型的对象，只交换其中两个成员值
  cout << "显式具体化模板:使用编译器生成的交换函数交换\n";
  Swap(j1.salary, j2.salary);
  Swap(j1.floor, j2.floor);
}

void Show(const job &j) {
  cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}

// 优先级关系：非模板函数 > 显式具体化模板 > 显式实例化 > 函数模板