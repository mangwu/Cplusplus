#include "9.7.h" // 包含头文件以合并pers
#include <iostream>

namespace pers {
using std::cin;
using std::cout;
void getPerson(Person &rp) {
  cout << "输入第一个姓名:";
  cin >> rp.fname;
  cout << "输入第二个姓名:";
  cin >> rp.lname;
}
void showPerson(const Person &rp) {
  cout << rp.lname << ", " << rp.fname;
}
} // namespace pers

namespace debts {
using pers::getPerson;
using pers::showPerson;
void getDebt(Debt &rd) {
  getPerson(rd.name);
  std::cout << "输入欠款金额:";
  std::cin >> rd.amount;
}
void showDebt(const Debt &rd) {
  showPerson(rd.name);
  std::cout << ": $" << rd.amount << std::endl;
}
double sumDebts(Debt *ar, int n) {
  double total = 0;
  for (int i = 0; i < n; i++) {
    total += ar[i].amount;
  }
  return total;
}
} // namespace debts