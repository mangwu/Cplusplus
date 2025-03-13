#include <iostream>
#include <climits> // 包含符号常量的头文件
#define ZERO 0;    // 预处理定义常量0
using namespace std;
int main(void)
{
  // 无符号类型，前面4种类型都对应一个不存储负值的无符号变体，应对没有负数的场景

  // 添加unsigned进行声明
  unsigned short n_ushort_max = USHRT_MAX; // unsigned short int简称
  short n_ushort_min = 0;
  cout << "整型unsigned short int的数字范围" << n_ushort_min << "~" << n_ushort_max << endl;
  unsigned int n_uint_max = UINT_MAX; // 符号常量
  unsigned int n_uint_min = 0;
  cout << "整型unsigned int的数字范围" << n_uint_min << "~" << n_uint_max << endl;
  unsigned long n_ulong_max = LONG_MAX;
  unsigned long n_ulong_min = 0;
  cout << "整型unsigned long int的数字范围" << n_ulong_min << "~" << n_ulong_max << endl;
  unsigned long long n_ulong_long_max = ULLONG_MAX; // long long int的简称
  unsigned long long n_ulong_long_min = 0;
  cout << "整型unsigned long long的数字范围" << n_ulong_long_min << "~" << n_ulong_long_max << endl;

  // 数值溢出问题，当一个整型变量的数值增加或减少导致溢出了其能表达的数值范围，就会发生上溢或者下溢
  // 例如short int 范围在

  return 0;
}