#include "9.1.h" // include下面的函数定义需要的结构体
#include <iostream>
#include <cmath>
using namespace std;

// B.包含与结构有关的函数定义代码
polar rect_to_polar(rect xypos) {
  polar answer;
  answer.distance = sqrt(pow(xypos.x, 2) + pow(xypos.y, 2));
  answer.angle = atan2(xypos.y, xypos.x); // 反正切，会返回弧度
  return answer;
}

// 按值传递，不需要加const，dapos是一个新的副本
void show_polar(polar dapos) {
  const double Rad_to_deg = 180 / M_PI;
  cout << "distance = " << dapos.distance;
  cout << " angle = " << dapos.angle * Rad_to_deg << " degrees." << endl;
}