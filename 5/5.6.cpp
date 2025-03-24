#include <iostream>
#include <string>

using namespace std;

int main(void) {
  cout << "输入word:";
  string word;
  getline(cin, word);
  cout << "反转字符如下" << endl;
  for (int i = word.size() - 1; i >= 0; i--) {
    cout << word[i];
  }
  return 0;
}