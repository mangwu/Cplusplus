#include <iostream>

const int Fave = 27;

using namespace std;

int main(void) {
  int n;
  cout << "输入1-100的数字" << endl;
  do {
    cin >> n;
    if (n < Fave) {
      cout << "Too low -- guess again:\n";
    } else if (n > Fave) {
      cout << "Too High -- guess again:\n";
    } else {
      cout << "ans is " << n << endl;
    }
  } while (n != Fave);
  return 0;
}