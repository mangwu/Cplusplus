#include <iostream>
using namespace std;

int main(void)
{
  int abc123_a = 2; // 字符数字下划线，不能以数字开头，区分大小写，不限制长度，但不能使用关键字
  int _abc = 1; // 合法但不建议
  int __abc = 1; // 合法但不建议
  return 0;
}