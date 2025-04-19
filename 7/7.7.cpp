#include <iostream>

const int MAX = 5;

using namespace std;

int fill_array(double *, int);
void show_array(const double *, int); // double *加了const，不可修改数组元素内容
void revalue(double *, int, double);

int main(void) {
  double properties[MAX];
  int size = fill_array(properties, MAX);
  show_array(properties, size);
  if (size > 0) {
    // 录入的值大于0，可以进行重新评估
    cout << "输入重新评估系数:";
    double factor;
    while (!(cin >> factor)) {
      // 捕获错误
      cin.clear();
      while (cin.get() != '\n')
        continue; // 清空缓冲区的无效内容
      cout << "Bad Input; Please Enter a numbber:";
    }
    revalue(properties, size, factor);
    show_array(properties, size);
  }
  return 0;
}

int fill_array(double *ar, int limit) {
  double temp;
  for (int i = 0; i < limit; i++) {
    cout << "输入值 #" << (i + 1) << ":";
    cin >> temp;
    if (!cin) {
      // 没有捕获成功
      cin.clear();              // 重置失效位
      while (cin.get() != '\n') // 清空缓冲区的无效内容
        continue;
      cout << "Bad Input; input process terminated\n";
      return i;
    } else if (temp < 0) { // 不需要负数
      return i;
    }
    ar[i] = temp; // 填充第i个元素
  }
  return limit;
}
// 不能修改ar里的内容，需要使用const保证ar中的元素不被改变
// *ar不应该被改变
void show_array(const double *ar, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Property #" << (i + 1) << ": $" << ar[i] << endl;
  }
}

void revalue(double *ar, int size, double factor) {
  for (int i = 0; i < size; i++) {
    ar[i] = ar[i] * factor;
  }
}