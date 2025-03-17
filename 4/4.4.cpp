#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  const int ArrSize = 20;
  char name[ArrSize];
  char dessert[ArrSize];
  cout << "输入字符串给name赋值:\n";
  cin.getline(name, ArrSize); // 使用cin.getline()获取输入，其终止条件是换行符或者读取字符个数为规定最大字符数
  cout << "输入字符串给dessert赋值:\n";
  cin.getline(dessert, ArrSize); // 通过getline()获取输入不会在缓冲区遗留换行符，但是cin >> 和cin.get()会遗留
  cout << "dessert:" << dessert << endl;
  cout << "name:" << name << endl;
  cout << "length of dessert:" << strlen(dessert) << endl;
  cout << "length of name:" << strlen(name) << endl;
  cout << "name[10] = " << (name[10] == '\0') << endl; // name长度为10是，name[10]为'\0'
  return 0;
}