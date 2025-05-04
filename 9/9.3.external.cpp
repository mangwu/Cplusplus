#include <iostream>

using namespace std;
void local();
void update(double dt);
// 静态外部变量
double warming = 0.3;

int main(void) {
  cout << "全局变量warming = " << warming << endl;
  update(0.1);
  cout << "全局变量warming = " << warming << endl;
  local();
  cout << "全局变量warming = " << warming << endl;
  return 0;
}