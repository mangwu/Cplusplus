#include <iostream>

using namespace std;

int main()
{
  int yams[3]; // 数组声明
  // yams = {7, 8, 6}; // 定义完成后，不允许成员初始化列表，也不能用另一个数组进行赋值会报错
  yams[0] = 7;
  yams[1] = 8;
  yams[2] = 6;

  int yamcosts[3] = {20, 30, 5}; // 成员初始化列表赋值，只能在定义时使用
  cout << "yams数量:" << yams[0] + yams[1] + yams[2] << endl;
  cout << "3种yams的价格:" << yamcosts[0] << "," << yamcosts[1] << "," << yamcosts[2] << endl;
  int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
  cout << "价格总和:" << total << endl;
  cout << "yams数组的大小(字节):" << sizeof yams << endl;
  cout << "yams数组第一个元素的大小(字节):" << sizeof yams[1] << endl;

  int totals[500] = {1}; // 除了第一个元素为1，剩余的元素都默认为0
  cout << "totals[499] =" << totals[499] << endl;
  short things[] = {1, 5, 23, 8};                // 初始化声明数组不声明数组长度，会计算成员列表的长度并规定数组长度
  int thingsLen = sizeof things / sizeof(short); // 常用于计算数组的长度
  cout << "things数组的长度:" << thingsLen << endl;

  return 0;
}