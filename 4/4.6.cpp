#include <iostream>

using namespace std;

int main(void)
{
  cout << "输入 year:";
  int year;
  // cin >> year; // 会遗留回车换行符 cin >> year会返回cin，可以链式调用
  (cin >> year).get(); // 这样写就不会遗留回车换行符
  // cin.get(); // 搞定回车换行符
  // cin.get(ch); // 另外一个重载函数，将捕获内容放到ch中，也会解决回车换行符
  cout << "输入地址address：";
  char address[80];
  cin.getline(address, 80); // 如果上述没有解决回车换行符，此时缓冲区中有回车换行符，
                            // 符合终止条件，所以会得到一个空字符串，回车换行符被遗弃
  cout << "year = " << year << endl;
  cout << "address = " << address << endl;
  return 0;
}