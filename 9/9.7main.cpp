#include "9.7.h"
#include <iostream>

int main(void) {
  using debts::Debt;
  using debts::showDebt;
  Debt golf = {"Benney", "Goatsniff", 120.0};
  showDebt(golf);
  other();
  another();
  return 0;
}

void other() {
  using std::cin;
  using std::cout;
  using std::endl;
  using namespace debts;
  Person dg = {"Doodles", "Glister"};
  showPerson(dg); // debts中已经using引用过了
  cout << endl;
  Debt zippy[3];
  for (int i = 0; i < 3; i++) {
    getDebt(zippy[i]);
  }
  for (int i = 0; i < 3; i++) {
    showDebt(zippy[i]);
  }
  cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
  return;
}
void another() {
  using pers::Person;
  Person collector = {"Milo", "Rightshift"};
  // 这里不用pers也识别到showPerson
  // ADL机制,因为这个函数的参数类型person结构定义在pers命名空间里，
  // 编译器会自动取pers命名空间中查找这个函数的定义
  showPerson(collector);
  std::cout << std::endl;
}