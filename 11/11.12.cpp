#include "11.10.h"
#include <iostream>

int main(void) {
  using std::cout;
  Time aida(3, 35);
  Time tosca(2, 48);
  Time temp;

  cout << "Aida  " << aida << "Tosca " << tosca; // operator<<()
  temp = aida + tosca;                             // operator+()
  cout << "Aida + Tosca = " << temp;                 // operator<<()
  temp = aida * 1.17;                              // operator*()
  cout << "aida * 1.17 = " << temp;                   // operator<<()
  cout << "10.0 * Tosca = " << 10.0 * tosca; //  friend operator*() operator<<()
  return 0;
}