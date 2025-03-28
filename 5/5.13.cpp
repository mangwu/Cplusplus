#include <iostream>

using namespace std;
const int ArSize = 20;

int main(void) {
  char name[ArSize];
  cout << "输入姓名：";
  cin >> name;
  cout << "name中每个字符的ascii码：\n";
  int i = 0;
  while (name[i] != '\0') {
    cout << name[i] << " : " << int(name[i]) << endl;
    i++;
  }
  return 0;
}