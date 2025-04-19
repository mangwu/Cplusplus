#include <iostream>

using namespace std;

int sum_arr(int *arr, int n);
const int ArrSize = 8;
int main(void) {
  int cookies[ArrSize] = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << "cookies = " << cookies << endl;                // 输出cookies的地址
  cout << "sizeof cookies = " << sizeof(cookies) << endl; // 输出cookies的大小
  int sum = sum_arr(cookies, ArrSize);    // 调用函数，计算数组之和
  cout << "Total eaten: " << sum << endl; // 输出总和

  sum = sum_arr(cookies, 3);                    // 调用函数，计算前3个元素之和
  cout << "First three eaten: " << sum << endl; // 输出总和

  return 0;
}

int sum_arr(int *arr, int n) { // 函数定义，计算数组之和
  int total = 0;
  cout << "arr = " << arr << endl;                // 输出arr的地址
  cout << "sizeof arr = " << sizeof(arr) << endl; // 输出arr的大小，会是地址长度
  for (int i = 0; i < n; i++) {
    total += arr[i]; // 累加数组元素
  }
  return total; // 返回数组之和
}