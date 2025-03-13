#include <iostream>
using namespace std;
int main(void)
{
  // 整型，一个整数，不同整型有不同的内存空间
  int maxInt = 2147483647; // 2 ** 31 - 1
  int minInt = -2147483648; // - 2 ** 31
  cout << minInt << endl;
  cout << maxInt << endl;
  return 0;
}