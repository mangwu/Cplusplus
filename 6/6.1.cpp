#include <iostream>

using namespace std;

int main(void) {
  char ch;
  int spaces = 0;
  int total = 0;
  cin.get(ch);
  while (ch != '.') { // 终止符
  // if语句，判断ch为空字符
    if (ch == ' ') {
      spaces++;
    }
    total++;
    cin.get(ch);
  }
  cout << spaces << " spaces, " << total;
  cout << " characters total in sentence\n";
  return 0;
}