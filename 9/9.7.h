#include <string>

namespace pers {
struct Person {
  std::string fname;
  std::string lname;
};
// 头文件声明函数
void getPerson(Person &rp);
void showPerson(const Person &rp);
}; // namespace pers

namespace debts {
using pers::Person;
struct Debt {
  Person name;
  double amount;
};
void getDebt(Debt &rd);
void showDebt(const Debt &rd);
double sumDebts(Debt *ar, int n);
}; // namespace debts

void other();

void another();