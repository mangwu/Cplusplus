#include <cstring>
#include <iostream>
using namespace std;

char *getName(void); // 函数声明，用于提示后面调用

int main(void) {
  char *name;
  name = getName(); // getname返回一个地址，让name指向这个地址
  cout << name << " at " << (int *)name << endl;
  delete[] name;
  name = getName(); // 不保证返回的内存空间地址相同
  cout << name << " at " << (int *)name << endl;
  delete[] name;
  return 0;
}

char *getName(void) {
  char temp[80]; // 临时字符串，以最大字符串长度开辟内存空间
  cout << "输入名称name:";
  cin.get(temp, 79).get();
  char *pn = new char[strlen(temp) + 1];
  strcpy(pn, temp);
  // 这里不能返回temp，因为在temp时系统创建的内存空间
  // 当getName被调用完毕后，temp表示的数组会被系统收回
  // 这个时候temp表示的地址的字符数组内容是不可预知的
  return pn;
}
