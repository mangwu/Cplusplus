#include <iostream>

using namespace std;
// 特征码：const double * 和 int
const double *f1(const double ar[], int n);
// 下面几种写法相同，都是f1的函数原型
// const double *f1(const double [], int);
// const double *f1(const double *, int);

const double *f2(const double[], int);

const double *f3(const double *, int n);

// 使用typedef简化声明类型
typedef const double *(*p_fun)(const double *, int);
// 定义p_fun是一个函数指针的别名

int main(void) {
  double av[3] = {1112.3, 1543.6, 2227.9};
  const double *(*p1)(const double *, int) = f1; // 创建一个函数指针
  auto p2 = f2;
  // const double *(*p2)(const double *, int) = f2; // 等价于这么声明
  cout << "Address\t\tvalue\n";
  // 第二个写法中，*的优先级比较低，所以不用括号,相当于f1(av,3)和 *(f1(av,3))
  cout << (*p1)(av, 3) << "\t" << *(*p1)(av, 3) << endl;
  // C++表示，(*p1)和p1可以等价使用(仅限于函数指针)
  cout << p1(av, 3) << "\t" << *p1(av, 3) << endl;
  cout << p2(av, 3) << "\t" << *p2(av, 3) << endl;

  // 函数指针数组，pa[3]是一个数组，前面有*，表示数组中每个元素是一个指针
  // 这个指针指向一个函数，所以pa是一个函数指针数组
  const double *(*pa[3])(const double *, int) = {f1, f2, f3};
  // auto pb = pa; // pb是指向pa这个函数指针数组第一个元素的指针
  const double *(**pb)(const double *, int) = pa;
  // pb是一个指针，写成*pb，然后因为它指向的元素也是一个指针，所以写成**pb
  // *pb表示pa的第一个元素，**pb表示的就是f1这个函数，所以在左右加上f1的特征码
  cout << (*pb)(av, 3) << "\t" << *(*pb)(av, 3) << endl;
  cout << "Address\t\tvalue\n";
  for (int i = 0; i < 3; i++) {
    cout << (*(pa[i]))(av, 3) << "\t" << *(*(pa[i]))(av, 3) << endl;
    // pa[i]是一个函数指针,调用pa[i]和*pa[i]等同，调用的时候可以省略*，如下
    cout << pa[i](av, 3) << "\t" << *pa[i](av, 3) << endl;
  }
  cout << "Address\t\tvalue\n";
  for (int i = 0; i < 3; i++) {
    cout << pb[i](av, 3) << "\t" << *pb[i](av, 3) << endl;
  }

  // auto pc = &pa; // pc指向整个函数指针数组,&pa是整个元素的地址
  // *pc是一个指向整个数组的指针，pa是一个3个元素的数组，所以应该是 (*pc)[3]
  // 因为这三个元素每个元素都是地址，所以应该是 *((*pc)[3])
  // 每个元素的地址指向的都是一个函数的入口，最后加上函数的特征码即可
  const double *(*(*pc)[3])(const double *, int) = &pa;
  cout << "Address\t\tvalue\n";
  for (int i = 0; i < 3; i++) {
    cout << (*pc)[i](av, 3) << "\t" << *(*pc)[i](av, 3) << endl;
  }

  const double *(*(*pd)[3])(const double *, int) = &pa;
  const double *pdb = (*pd)[1](av, 3);
  cout << pdb << "\t" << *pdb << endl;
  cout << (*(*pd)[2])(av, 3) << "\t" << *(*(*pd)[2])(av, 3) << endl;
  cout << "Address\t\tvalue\n";
  
  // 使用typedef定义的p_fun进行简化
  p_fun p11 = f1;
  p_fun paa[3] = {f1, f2, f3};
  p_fun(*pdd)[3] = &paa;
  for (int i = 0; i < 3; i++) {
    cout << paa[i](av, i) << "\t" << *paa[i](av, i) << endl;
    cout << (*pdd)[i](av, i) << "\t" << *(*pdd)[i](av, i) << endl;
  }

  return 0;
}

const double *f1(const double *ar, int n) {
  return ar; // 第一个元素的地址
}

const double *f2(const double ar[], int n) {
  return ar + 1; // 第二个元素的地址
}

const double *f3(const double ar[], int n) {
  return ar + 2; // 第三个元素的地址
}