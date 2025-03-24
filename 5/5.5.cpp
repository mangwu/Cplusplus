#include <iostream>

using namespace std;

int main(void) {
  cout << "输入步长:";
  int by;
  cin >> by;
  for (int i = 0; i < 100; i = i + by) {
    cout << i << endl;
  }
  return 0;
}