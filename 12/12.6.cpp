#include "12.4.h"
#include <iostream>

const int ArSize = 10;
const int MaxLen = 81;

using namespace std;

int main(void) {
  String name;
  cout << "hi, what's your name?\n";
  cin >> name;
  cout << name << ", please enter up to " << ArSize
       << " short sayings <empty line to quit>:\n";
  String sayings[ArSize];
  char temp[MaxLen];
  int total = 0;
  for (int i = 0; i < ArSize; i++) {
    cout << i + 1 << ": ";
    cin.get(temp, MaxLen);
    while (cin && cin.get() != '\n') {
      continue; // 清除缓冲区
    }
    if (!cin || temp[0] == '\0') { // 空行
      break;
    } else {
      sayings[i] = temp; // 重载赋值运算符
    }
    total++;
  }
  if (total > 0) {
    cout << "Here are your sayings:\n";
    for (int i = 0; i < total; i++) {
      cout << sayings[i][0] << ": " << sayings[i] << endl;
    }
    cout << "This program used " << String::howMany()
         << " String objects. Bye.\n";
  }
  return 0;
}