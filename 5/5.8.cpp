#include <iostream>

using namespace std;
int main(void) {
  double number;
  double sum = 0.0;
  for (int i = 1; i <= 5; i++) {
    cout << "value " << i << ": ";
    cin >> number;
    sum += number;
  }
  cout << "sum = " << sum << endl;
  cout << "average = " << sum / 5 << endl;
  return 0;
}