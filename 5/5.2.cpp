#include <iostream>

using namespace std;

int main(void) {
  cout << "输入循环次数：";
  int limit;
  cin >> limit;
  int i;
  for (i = limit; i; i--) {
    cout << "i = " << i << endl;
  }
  cout << "循环完毕，i = " << i << endl;
  return 0;
}