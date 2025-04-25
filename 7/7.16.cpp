#include <iostream>
using namespace std;
void countdown(int n);
int main() {
  countdown(4);
  return 0;
}

// 递归函数
void countdown(int n) {
  // 递归调用之前的语句相当于入栈前的执行，会顺序执行
  cout << "count down... " << n << " " << &n << endl;
  if (n > 0) {
    countdown(n - 1);
  }
  // 递归调用之后的语句时出栈后的执行，会逆序执行
  cout << n << " kaboom! " << &n << endl;
}