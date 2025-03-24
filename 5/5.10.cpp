#include <iostream>

using namespace std;

int main(void) {
  int quizscores[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};
  // == 条件用于判断两个值是否相等，这种书写不会报错，但存在潜在的问题
  // 不应该让i超过quizsores的长度，否则会可能访问到未知地址
  for (int i = 0; quizscores[i] == 20; i++) {
    cout << "quiz " << i << " is a 20\n";
  }
  return 0;
}