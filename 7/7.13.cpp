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
void rect_to_polar(const rect *pxy, polar *pda);
void show_polar(const polar *dapos);
int main(void) {
  // 创建两个对象
  rect rplace;
  polar pplace;
  cout << "输入x，y以填充直角坐标系:";
  while (cin >> rplace.x >> rplace.y) { // 通过cin获取直角坐标系坐标
    rect_to_polar(&rplace, &pplace);
    show_polar(&pplace);
    cout << "Next two numbers(q to quit):";
  }
  return 0;
}

// 传递给来的是一个指向具体直角坐标对象的地址，为了让原始的坐标对象不被改变，加const
// 同理，为了节省空间，也不要返回一个polar对象，
// 直接传递外部的直角坐标对象的地址进行修改即可，但是不加const，因为要进行更改
void rect_to_polar(const rect *pxy, polar *pda) {
  pda->distance = sqrt(pow(pxy->x, 2) + pow(pxy->y, 2));
  pda->angle = atan2(pxy->y, pxy->x); // 反正切，会返回弧度
}

const double Rad_to_deg = 180 / M_PI;

void show_polar(const polar *dapos) {
  cout << "distance = " << dapos->distance;
  cout << " angle = " << dapos->angle * Rad_to_deg << " degrees." << endl;
}