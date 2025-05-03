#include <iostream>

using namespace std;

// 两个left函数，不同的参数类型，所以是函数重载
char *left(const char *str, int n = 1);
unsigned long left(unsigned long num, unsigned ct);
int main(void) {
  const char *trip = "Hawaii!!";
  unsigned long n = 12345678;
  char *temp;
  for (int i = 1; i < 10; i++) {
    cout << left(n, i) << endl;
    temp = left(trip, i);
    cout << temp << endl;
    delete[] temp; // 截取字符串的返回的是一个指向new出来的char数组，需要删除
  }
  return 0;
}

char *left(const char *str, int n) {
  if (n < 0) {
    n = 0;
  }
  int m = 0;
  while (str[m] != '\0') {
    m++;
  }
  n = (n > m ? m : n);
  char *p = new char[n + 1];
  int i;
  for (i = 0; i < n; i++) {
    p[i] = str[i];
  }
  while (i <= n) {
    p[i++] = '\0';
  }
  return p;
}

// 截取数字的前ct个
unsigned long left(unsigned long num, unsigned ct) {
  unsigned digits = 1;
  unsigned long n = num;
  if (ct == 0 || num == 0) {
    return 0; // 未截取任何数
  }
  // 计算num的位数
  while (n /= 10) {
    digits++;
  }
  // 全部截取
  if (ct >= digits) {
    return num;
  }
  ct = digits - ct;
  while (ct--) {
    num /= 10;
  }
  return num;
}