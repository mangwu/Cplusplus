#include "10.1.h"
#include <iostream>
#include <string>
// 在类外写函数定义，需要通过::域解析符号定义

void Stock::acquire(const std::string &co, long n, double pr) {
  Stock::company = co;
  // 在这个括号内，作用域就是Stock，所以上面语句的Stock::可以省略
  if (n < 0) {
    std::cout << "Number of Shares Can't be engative;" << company
              << " shares set to 0\n";
    // 省略了Stock::
    shares = 0;
  } else {
    shares = n;
  }
  share_val = pr;
  set_total();
}

void Stock::bug(long num, double price) {
  if (num < 0) {
    std::cout << "Number of shares purchased can't be negative."
              << "Transaction is aborted.\n";
  } else {
    shares += num;
    share_val = price;
    profit -= num * price;
    set_total();
  }
}

void Stock::sell(long num, double price) {
  using std::cout;
  if (num < 0) {
    cout << "Number of shares sold can't be negative.\n"
         << "Transaction is aborted.\n";
  } else if (num > shares) {
    cout << "You can't sell more than you have!" << "Transaction is aborted.\n";
  } else {
    shares -= num;
    share_val = price;
    profit += num * price;
    set_total();
  }
}

void Stock::update(double price) {
  share_val = price;
  set_total();
}

void Stock::show() {
  using std::cout;
  using std::endl;
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout.precision(3);
  cout << "Company " << company << endl;
  cout << "shares " << shares << endl;
  cout << "shares price: $ " << share_val << endl;
  cout << "Total Worth: $ " << total_val << endl;
  cout << "profit: $ " << profit << endl;
}

// 想要在类声明外定义内联成员函数，需要主动使用inline，如下
// 根据内联的内部链接性，这个定义只对当前文件有效，
// 其他文件使用这个内联函数也需要进行相同定义
// 最简单的方法就是在头文件类声明的时候就定义好内联函数
// 这也是在类声明就定义的函数默认是内联函数的原因
inline void Stock::show_total() {
  using std::cout;
  using std::endl;
  cout << "Total Worth: $ " << total_val << endl;
}

// 自定义构造函数
Stock::Stock(const std::string &co, long n, double pr) {
  company = co;
  if (n < 0) {
    std::cout << "Number of Shares Can't be engative;" << company
              << " shares set to 0\n";
    shares = 0;
  } else {
    shares = n;
  }
  share_val = pr;
  set_total();
}