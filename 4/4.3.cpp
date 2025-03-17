#include <iostream>
using namespace std;

int main(void)
{
  const int ArrSize = 20;
  char name[ArrSize];
  char dessert[ArrSize];
  cout << "输入字符串给name赋值:\n";
  cin >> name; // cin使用空白(空格、制表符，换行符)确定字符结束的位置，如果输入name有空格且后续有字符，
               // 则后续字符会作为dessert的字符
  cout << "输入字符串给dessert赋值:\n";
  cin >> dessert;
  cout << "dessert:" << dessert << endl;
  cout << "name:" << name << endl;
  return 0;
}