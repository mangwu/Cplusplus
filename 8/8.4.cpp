#include <iostream>

using namespace std;

void swapr(int &, int &);
void swapp(int *, int *);
void swapv(int a, int b);

int main(void) {
  int wallet1 = 100;
  int wallet2 = 350;
  cout << "name\tvalue" << endl;
  cout << "wallet1\t" << wallet1 << endl;
  cout << "wallet2\t" << wallet2 << endl;
  cout << "using reference to swap content:\n";
  swapr(wallet1, wallet2);
  cout << "name\tvalue" << endl;
  cout << "wallet1\t" << wallet1 << endl;
  cout << "wallet2\t" << wallet2 << endl;
  cout << "using pointer to swap content:\n";
  swapp(&wallet1, &wallet2);
  cout << "name\tvalue" << endl;
  cout << "wallet1\t" << wallet1 << endl;
  cout << "wallet2\t" << wallet2 << endl;
  cout << "try to use passing by value:\n";
  swapv(wallet1, wallet2); // 不会影响wallet1和wallet2
  cout << "name\tvalue" << endl; 
  cout << "wallet1\t" << wallet1 << endl;
  cout << "wallet2\t" << wallet2 << endl;
  return 0;
}
void swapr(int &a, int &b) {
  int tem = b;
  b = a;
  a = tem;
}
void swapp(int *a, int *b) {
  int tem = *a;
  *a = *b;
  *b = tem;
}

void swapv(int a, int b) {
  int tem = a;
  a = b;
  b = tem;
}