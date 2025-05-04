// #pragma once // 这个语句和下面的重复定义解决方案做的是同样一件事
// 预编译阶段定义一次NINE_ONE_H_，保证结构和函数原型只定义一次
// 如果有多次的#include "9.1.h"
// 从二次开始不会再定义结构和函数原型，避免重复include
#ifndef NINE_ONE_H_ // 重复定义的解决方案
#define NINE_ONE_H_
// A.包含结构声明和使用这些结构的原型放入头文件
// 好处：
//     1.其他多个文件都可以引用这些结构和函数
//     2.修改时只用维护这一个头文件
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
#endif