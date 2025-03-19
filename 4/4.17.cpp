#include <iostream>
using namespace std;

int main(void) {
  int nights = 1001;
  int *pt = new int; // 分配一个未命名的内存空间
  *pt = 1001;

  cout << "nights的值：" << nights << endl;
  cout << "nights的地址：" << &nights << endl;

  cout << "*pt的值：" << *pt << endl;
  cout << "pt指针表示的地址：" << pt << endl;
  cout << "sizeof pt " << sizeof(pt)
       << endl; // 8 编译器或者系统不同可能导致结果不同
  cout << "sizeof *pt " << sizeof(*pt) << endl;

  double *pd = new double;
  *pd = 10000001.0;
  cout << "*pd的值：" << *pd << endl;
  cout << "pd指针表示的地址：" << pd << endl;
  cout << "sizeof pd " << sizeof(pd) << endl;
  cout << "sizeof *pd " << sizeof(*pd) << endl;

  delete pt; // 清空pt指向的内存空间,但是pt变量本身还存在,它可以指向其它内存空间
  cout << "----delete pt;----\n";
  cout << "pt = " << pt << endl;
  cout << "*pt = " << *pt << endl; // 不确定的
  cout << "------------------\n";
  pt = &nights; // 把pt指向nights变量的内存空间
  // delete pt;    // 不允许，因为delete只能删除用new开辟内存空间，二者要匹配
  int *ps = new int;
  pt = ps;   // 把ps指向的内存空间地址赋值给pt
  delete pt; // 可以，delete用于new分配的内存，关键指向的内存地址是new开辟的
  // delete ps; // 不可以，不要释放两次同一个内存块，结果不确定
  pt = nullptr;
  ps = nullptr;
  delete pt; // delete用于空指针是安全的
  return 0;
}