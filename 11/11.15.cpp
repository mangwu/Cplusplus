#include "11.13.h"
#include <cstdlib> // 提供rand()和srand()原型
#include <ctime>
#include <fstream>
#include <iostream>

int main(void) {
  using namespace std;
  using VECTOR::Vector;
  // srand用于初始化随机数生成器的种子。
  // 如果你使用相同的种子来调用srand()，那么你将得到相同的随机数序列。
  srand(time(0));          // time(0)返回当前时间，srand()以此为种子，
  double direction;        // 角度方向
  Vector step;             // 行动矢量
  Vector result(0.0, 0.0); // 最终所处位置
  unsigned long steps = 0; // 当前输入的行动次数
  double target;           // 目标距离
  double dstep;            // 行动的矢量长度(步长)

  // Vector重载<<运算符时使用ostream类作为传入参数类型，所以也可以使用ofstream
  ofstream fout;
  fout.open("thewalk.txt");

  cout << "输入目标距离(q to quit):";
  while (cin >> target) {
    cout << "输入步长:";
    if (!(cin >> dstep)) {
      break;
    }
    while (result.magval() < target) {
      direction = rand() % 360; // 随机角度方向
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
    }
    cout << "经过" << steps << "步，当前位置在：\n";
    cout << result;
    // 重载对fout有效
    fout << "经过" << steps << "步，当前位置在：\n";
    fout << result << endl;
    result.polar_mode();
    cout << result;
    cout << "每步的平均行动距离为：" << result.magval() / steps << endl;
    steps = 0;
    result.reset(0.0, 0.0);
    cout << "输入目标距离(q to quit):";
  }
  cin.clear();
  fout.close();
  while (cin.get() != '\n') {
    continue;
  }
  return 0;
}