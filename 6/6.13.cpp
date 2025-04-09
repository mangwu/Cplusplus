#include <iostream>

using namespace std;

const int Max = 5;

int main(void) {
  double fish[Max];
  cout << "输入最多5条鱼的重量。\n";
  cout << "输入q键退出输入:\n";
  cout << "fish #1:";
  int i = 0;
  // cin >> fish[i] 如果正常输入会返回cin，错误输入会返回false
  while (i < Max && cin >> fish[i]) {
    if (++i < Max) {
      cout << "fish #" << (i + 1) << ":";
    }
  }
  double total = 0.0;
  for (int j = 0; j < i; j++) {
    total += fish[j];
  }
  if (i == 0) {
    cout << "没有鱼\n";
  } else {
    cout << i << "条鱼的平均重量" << (total / i) << endl;
  }
  return 0;
}