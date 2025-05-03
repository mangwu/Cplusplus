#include <iostream>
using namespace std;
struct job {
  char name[40];
  double salary;
  int floor;
};

// 函数模板的原型
template <typename T>
void Swap(T &a, T &b);
// 函数模板
template <typename T>
void Swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}
void Show(const job &j);

// char类型的显式实例化，显式实例化，提前
// 必须在函数模板定义之后
// 不允许在函数内部使用 template 来显式实例化模板
template void Swap<char>(char &, char &);

// 显式具体化模板的原型
template <>
void Swap<job>(job &a, job &b);

// 显式实例化，隐式实例化，显式具体化统称为具体化

// 注意：不能在同一个文件使用同一类型的显式实例化和显式具体化
// 但是如果编译器先看到显式具体化，那么后面再出现式实例化也没关系，如下
// 前面有显式具体化了，整个模板不会生成函数，但是不能放在显式具体化上面
template void Swap<job>(job &, job &);

int main(void) {
  int x = 10;
  int y = 20;
  Swap(x, y); // int的隐式实例化
  cout << "x " << x << endl;
  cout << "y " << y << endl;
  char a = 'a';
  char b = 'b';
  Swap(a, b); // char的显式实例化
  cout << "a " << a << endl;
  cout << "b " << b << endl;

  job j1 = {"job1", 89554.24, 3};
  job j2 = {"job2", 86477.574, 5};
  Swap(j1, j2); // Job的显式具体化
  Show(j1);
  Show(j2);

  short i = 52;
  short j = 55;
  // short的显式实例化，使用<short>会强制使用显式具体化或者模板实例化
  // 即使有非模板函数
  Swap<short>(i, j); // 使用<short>强制使用模板，优先级大于非模板函数
  cout << "i " << i << endl;
  cout << "j " << j << endl;
  return 0;
}

// 显式具体化模板
template <>
void Swap<job>(job &a, job &b) {
  Swap(a.floor, b.floor);
  Swap(a.salary, b.salary);
}

void Show(const job &j) {
  cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
