#include <cmath>
#include <iostream>
using namespace std;

// 极坐标系
struct polar {
  double distance;
  double angle;
};

// 直角坐标系
struct rect {
  double x;
  double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
int main(void) {
  // 创建两个对象
  rect rplace;
  polar pplace;
  cout << "输入x，y以填充直角坐标系:";
  while (cin >> rplace.x >> rplace.y) { // 通过cin获取直角坐标系坐标
    pplace = rect_to_polar(rplace);
    show_polar(pplace);
    cout << "Next two numbers(q to quit):";
  }
  return 0;
}

polar rect_to_polar(rect xypos) {
  polar answer;
  answer.distance = sqrt(pow(xypos.x, 2) + pow(xypos.y, 2));
  answer.angle = atan2(xypos.y, xypos.x); // 反正切，会返回弧度
  return answer;
}

const double Rad_to_deg = 180 / M_PI;

// 按值传递，不需要加const，dapos是一个新的副本
void show_polar(polar dapos) {
  cout << "distance = " << dapos.distance;
  cout << " angle = " << dapos.angle * Rad_to_deg << " degrees." << endl;
}