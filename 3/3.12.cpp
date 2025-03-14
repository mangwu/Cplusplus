#include <iostream>

using namespace std;

int main(void)
{
  const int Lbs_per_stn = 14; // 一英石等于14磅
  int lbs;
  cout << "输入以磅为单位的体重：";
  cin >> lbs;
  int stone = lbs / Lbs_per_stn;  // 英石数，整除的数
  int pounds = lbs % Lbs_per_stn; // 余下的磅数
  cout << lbs << "磅的重量为：" << stone << "英石，" << pounds << "磅" << endl;
  return 0;
}