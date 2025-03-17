#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  const int ArrSize = 20;
  char name[ArrSize];
  char dessert[ArrSize];
  cout << "输入字符串给name赋值:\n";
  cin.get(name, ArrSize); // 使用cin.get()获取输入，其终止条件是换行符或者读取字符个数为规定最大字符数
  // cin.get(name, ArrSize).get(); // cin.get()带参的返回值是cin，可以链式调用get()去除换行符
  cout << "输入字符串给dessert赋值:\n";
  cin.get();                       // 读取下一个字符，可以用于处理换行符，为处理下一个字符做好准备
  cin.get(dessert, ArrSize).get(); // 通过get()获取输入会在缓冲区遗留换行符，所以如果没有上一行，本行会读取到回车换行符，会直接跳过
  cout << "dessert:" << dessert << endl;
  cout << "name:" << name << endl;
  cout << "length of dessert:" << strlen(dessert) << endl;
  cout << "length of name:" << strlen(name) << endl;
  cout << "name[10]是否是空字符 " << (name[10] == '\0') << endl; // name长度为10是，name[10]为'\0'
  return 0;
}