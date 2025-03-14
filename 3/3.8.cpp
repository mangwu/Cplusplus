#include <iostream>
using namespace std;
int main(void)
{
  // 默认情况，cout会把小数点后的0删除
  float a = 25.15400000;
  cout << "a:" << a << endl;
  cout << "-----设置定点模式----\n";
  cout.setf(ios_base::fixed, ios_base::floatfield); // 设置打印格式，让小数以定点模式输出，0会被保留，小数点后显示6位数字
  float tub = 10.0 / 3.0;                           // 3.3333...
  cout << "tub:" << tub << endl;
  const float million = 1.0e6;                       // 科学计数法
  cout << "million * tub:" << million * tub << endl; // 333333.250000
  // float能表示的位数有效精确位为24位，对于需要用4位表示的小数，其表示的10进制精度为6位，所以后面就不准确了
  cout << "10 * million * tub:" << 10 * million * tub << endl; // 333333.250000
  cout << "----mint是double类型----" << endl;
  double mint = 10.0 / 3.0;
  cout << "mint:" << mint << endl;
  cout << "million * mint:" << million * mint << endl;           // 333333.250000
  cout << "10 * million * mint:" << 10 * million * mint << endl; // 333333.250000
  return 0;
}