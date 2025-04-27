#include <iostream>
using namespace std;
int main(void) {
  int rats = 101;
  int &rodents = rats; // 绑定了就锁死了，rodents一直引用rats的内存空间
  cout << "rats = " << rats << endl;
  cout << "rodents = " << rodents << endl;
  cout << "&rats = " << &rats << endl;
  cout << "&rodents = " << &rodents << endl;

  cout << "name\t\tvalue" << endl;
  int bunnies = 50;
  rodents = bunnies; // 这里相当于赋值，把bunnies的值赋给rodents绑定的内存空间
  cout << "bunnies\t\t" << bunnies << endl;
  cout << "rats\t\t" << rats << endl;
  cout << "rodents\t\t" << rodents << endl;
  cout << "&bunnies\t" << &bunnies << endl;
  cout << "&rats\t\t" << &rats << endl;
  cout << "&rodents\t" << &rodents << endl;
  return 0;
}