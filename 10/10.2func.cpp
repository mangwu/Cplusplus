#include "10.2.h"
#include <iostream>
#include <string>
// 在类外写函数定义，需要通过::域解析符号定义

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

void Stock::show() const {
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

// 重构默认构造函数
Stock::Stock() {
  company = "no name";
  shares = 0;
  share_val = 0;
  set_total();
}
// 定义析构函数，析构函数应该不定义任何参数和返回值
Stock::~Stock() {
  std::cout << "Bye, " << company << "\n";
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

// 使用 this 的成员函数

const Stock &Stock::topval(const Stock &s) const {
  // 这里可以不要this，total_val是这种访问方式的简写
  if (s.total_val > this->total_val) {
    return s;
  } else {
    // this是指向调用成员函数的对象的指针
    return *this;
  }
}