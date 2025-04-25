#include <iostream>
#include <string>

using namespace std;
const int SIZE = 5;
void display(const string *list, int n);
int main(void) {
  string list[SIZE];
  cout << "Enter your " << SIZE << " string:\n";
  for (int i = 0; i < SIZE; i++) {
    cout << i + 1 << "#";
    getline(cin, list[i]);
  }
  cout << "Your list:\n";
  display(list, SIZE);
  return 0;
}
// 加上const ，表示 *list不能修改
void display(const string *list, int n) {
  for (int i = 0; i < n; i++) {
    cout << i + 1 << "#:" << list[i] << endl;
  }
}