#include <iostream>

using namespace std;
const int Cities = 5;
const int Years = 5;
int main(void) {
  // 字符串常量是不能改变的，所以要加const，表示*cities[i]是不可改变的
  const char *cities[Cities] = {
    "Gribble City", "Gribbletown",   "New Gribble",
    "San Gribble",  "Gribble Vista",
  };

  // 五个城市每年的最高温度问题
  // maxtemps是包括四个元素的数组，每个元素是包含五个int元素的数组
  int maxtemps[Years][Cities] = {
    {105, 100, 87, 101, 99},
    {96, 104, 91, 100, 104},
    {97, 101, 87, 106, 102},
    {98, 103, 87, 101, 108},
    {98, 103, 109, 101, 108},
  };

  cout << "计算每年的最高温度及其城市\n";
  for (int i = 0; i < Years; i++) {
    int maxTemp = 0;
    string city;
    for (int j = 0; j < Cities; j++) {
      if (maxtemps[i][j] > maxTemp) {
        maxTemp = maxtemps[i][j];
        city = cities[j];
      }
    }
    cout << (2011 + i) << "年的最高温度和城市是：";
    cout << maxTemp << "℉\t" << city << endl;
  }
  return 0;
}