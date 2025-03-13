#include <iostream>
#include <climits> // 包含符号常量的头文件
using namespace std;
int main(void)
{
  short n_short_max = SHRT_MAX; // short int简称
  short n_short_min = SHRT_MIN; // short int简称
  cout << "整型short int的数字范围" << n_short_min << "~" << n_short_max << endl;
  int n_int_max = INT_MAX; // 符号常量
  int n_int_min = INT_MIN;
  cout << "整型int的数字范围" << n_int_min << "~" << n_int_max << endl;
  long n_long_max = LONG_MAX; // long int简称
  long n_long_min = LONG_MIN; // long int简称
  cout << "整型long int的数字范围" << n_long_min << "~" << n_long_max << endl;
  long long n_long_long_max = LLONG_MAX; // long long int的简称
  long long n_long_long_min = LLONG_MIN;
  cout << "整型long long的数字范围" << n_long_long_min << "~" << n_long_long_max << endl;

  // sizeof可用于测量整型或其整型变量存储在内存中使用的空间大小（以字节为单位）
  // cout << "int的存储空间大小" << sizeof(int) << "bytes" << endl; // sizeof不是函数，对于整型必须使用括号
  cout << "short int的存储空间大小" << sizeof n_short_max << "bytes" << endl;
  cout << "int的存储空间大小" << sizeof n_int_max << "bytes" << endl;
  cout << "long int的存储空间大小" << sizeof n_long_max << "bytes" << endl;
  cout << "long long int的存储空间大小" << sizeof n_long_long_max << "bytes" << endl;

  cout << "-----------------------------" << endl;
  // 使用=号为C的赋值方式，C++也有自己的赋值方式
  // 1. 使用括号
  int a(5);
  cout << "使用括号赋值: 'int a(5);' : " << a << endl;
  // 2. 使用大括号，常用于数组和结构，但是也可也用于单值变量
  int b = {6};
  int c{7};
  cout << "使用大括号赋值: 'int b = {6};', 'int c{7};': " << b << "," << c << endl;
  return 0;
}