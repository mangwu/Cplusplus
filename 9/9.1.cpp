#include "9.1.h" // 包含头文件,include的作用就是把外部文件copy过来
#include <cmath> // 双引号和<>符号的区别是:双引号先到当前目录去查，然后再查库
#include <iostream>

// 头文件不能重复包含，如何9.1.h中include了iostream，这个时候就会报错，出现重复定义
#include "9.1.h" // 9.1.h 中进行了重复定义的解决方案，不会编译报错
using namespace std;


// C.包含调用与结构相关的函数的代码

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

