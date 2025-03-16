#include <iostream>
using namespace std;

int main(void)
{
  cout.setf(ios_base::fixed, ios_base::floatfield); // 设置定点模式
  float tree = 3;
  cout << "tree = " << tree << endl;   // 3.00000
  int guess(3.9832);                   // 将双精度浮点型赋值给int型
  cout << "guess = " << guess << endl; // 3
  int debt = 7.2e12;                   // double大于整型的21亿，结果不确定，不同系统不同
  cout << "debt = " << debt << endl;   // 2147483647

  // {}初始化列表不允许缩窄
  // char c1{31325}; // 不在char范围会运行失败并报错
  // cout << "c1 = " << c1 << endl;
  int x = 66;
  char c2 = {x}; // x是变量，值不确定，编译器会预测潜在的错误，如果是在范围内的常量就不会提示错误
  cout << "c2 = " << c2 << endl;
  char c3 = 31325;
  cout << "c3 = " << c3 << endl;
  return 0;
}