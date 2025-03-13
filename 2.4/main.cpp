#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double area; // 房间面积
  cin >> area;
  double side = sqrt(area); // 计算边长
  cout << side << endl;
  return 0;
}
