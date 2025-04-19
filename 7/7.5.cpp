#include <iostream>

const int ArSize = 8;

using namespace std;
int sum_arr(int arr[], int n); // 函数原型，计算数组之和
int main() {
  int cookies[ArSize] = {1, 2, 3, 4, 5, 6, 7, 8};
  int sum = sum_arr(cookies, ArSize); // 调用函数，计算数组之和
  cout << "Total cookies eaten: " << sum << endl;
  return 0;
}

// int arr[] 实际上是一个int *类型，表示arr是一个指针
int sum_arr(int arr[], int n) { // 函数定义，计算数组之和
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += arr[i]; // 累加数组元素
  }
  return total; // 返回数组之和
}