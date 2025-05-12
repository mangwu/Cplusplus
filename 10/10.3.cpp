#include "10.2.h"
#include <iostream>

const int STKS = 4;

int main(void) {
  using std::cout;
  using std::endl;
  Stock stocks[STKS] = {
    Stock("Nano Smart", 12, 20.0),
    Stock("Boffo Object", 200, 2.0),
    Stock("Monag Uiyucb", 130, 3.25),
    Stock("Fleep Poacuny", 60, 6.25),
  };
  cout << "Stock holdings: \n";
  int st;
  for (st = 0; st < STKS; st++) {
    stocks[st].show();
  }
  const Stock *top = &stocks[0];
  for (st = 1; st < STKS; st++) {
    top = &top->topval(stocks[st]);
  }
  cout << "Most valuable holding\n";
  top->show();
  return 0;
}