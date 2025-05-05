#include <iostream>
#include <new>
using namespace std;
const int BUF = 512;
const int N = 5;
// 在静态区开辟了512个字节的空间
char buffer[BUF];

int main(void) {
  double *pd1, *pd2;
  int i;
  // 定位new运算符和普通new运算符
  cout << "Calling new and placement new:\n";
  pd1 = new double[N]; // 在heap（堆）区开辟N个double类型的内存空间
  // 在buffer开始的静态区开辟N个double类型的内存空间
  pd2 = new (buffer) double[N];
  for (i = 0; i < N; i++) {
    pd2[i] = pd1[i] = 1000 + 8.0 * i;
  }
  cout << "Memory addresses:\n" << "heap: " << pd1 << endl;
  // buffer是一个char类型的，直接打印会打印字符串，
  // 所以使用void*将其转换为地址显示
  cout << "Memory addresses:\n" << "static: " << (void *)buffer << endl;
  cout << "Memory contents:\n";
  for (int i = 0; i < N; i++) {
    cout << pd1[i] << " at " << &pd1[i] << " (heap); ";
    cout << pd2[i] << " at " << &pd2[i] << " (static) .\n";
  }
  cout << "Calling new and placement new a second time:\n";
  double *pd3, *pd4;
  pd3 = new double[N];
  // 重新以buffer开始，开辟N个double类型的内存空间
  // 实际上不会重新开辟，只是把已经开辟的静态内存空间地址赋给它
  pd4 = new (buffer) double[N];
  for (i = 0; i < N; i++) {
    pd4[i] = pd3[i] = 2000 + 8.0 * i;
  }
  cout << "Memory contents:\n";
  for (int i = 0; i < N; i++) {
    cout << pd3[i] << " at " << &pd3[i] << " (heap); ";
    cout << pd4[i] << " at " << &pd4[i] << " (static) .\n";
  }
  cout << "Calling new and placement new a third time:\n";
  delete[] pd1;
  // 开辟新的堆内存空间
  pd1 = new double(N);
  // 在buffer的 5 * 8个字节后开始开辟内存空间
  // 实际上不会重新开辟，只是把已经开辟的静态内存空间地址赋给它
  pd2 = new (buffer + N * sizeof(double)) double[N];
  for (i = 0; i < N; i++) {
    pd1[i] = pd2[i] = 4000 + 8.0 * i;
  }
  cout << "Memory contents:\n";
  for (int i = 0; i < N; i++) {
    cout << pd1[i] << " at " << &pd1[i] << " (heap); ";
    cout << pd2[i] << " at " << &pd2[i] << " (static) .\n";
  }
  // delete[] pd2; // 不能删除静态内存，只能删除堆内存
  delete[] pd1;
  delete[] pd3;
  return 0;
}