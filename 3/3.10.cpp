#include <iostream>

using namespace std;

int main()
{
  // 浮点数都是一个不准确近似的值，因为小数部分的二进制可能无法完全表示
  float hats, heads;
  cout.setf(ios_base::fixed, ios_base::floatfield); // 设置定点模式
  cout << "输入hats:";
  cin >> hats; // 50.25
  cout << "输入heads:";
  cin >> heads; // 11.17
  cout << "hats = " << hats << endl;
  cout << "heads = " << heads << endl;
  cout << "hats + heads = " << hats + heads << endl; // 61.419998
  cout << "hats - heads = " << hats - heads << endl; // 39.080002
  cout << "hats * heads = " << hats * heads << endl; // 561.292480
  cout << "hats / heads = " << hats / heads << endl; // 4.498657
  return 0;
}