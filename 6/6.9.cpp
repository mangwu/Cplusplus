#include <iostream>

using namespace std;

int main(void) {
  int a, b;
  cout << "Enter two intergers: " << endl;
  cin >> a >> b;
  cout << "其中的大者为：" << (a > b ? a : b) << endl;

  return 0;
}