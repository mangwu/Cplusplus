#include <array>
#include <iostream>
#include <string>
using namespace std;

const int Seasons = 4;
const array<string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};
void fill(array<double, Seasons> *pa);
void show(array<double, Seasons> ar);
int main(void) {
  array<double, Seasons> expenses; //
  fill(&expenses);                 // 将对象的地址传递进去
  show(expenses);                  // 对象也可以直接传递
  return 0;
}

// 按地址传递
void fill(array<double, Seasons> *pa) {
  for (int i = 0; i < Seasons; i++) {
    cout << "输入" << Snames[i] << "的 expenses:";
    // pa是一个指向array对象的地址，*pa是array对象，array对象通过中括号运算符修改
    cin >> (*pa)[i];
  }
}

// 按值传递，传入的是对象的副本，不需要const
void show(array<double, Seasons> ar) {
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for (int i = 0; i < Seasons; i++) {
    cout << Snames[i] << ": " << ar[i] << endl;
    total += ar[i];
  }
  cout << "Total: " << total << endl;
}