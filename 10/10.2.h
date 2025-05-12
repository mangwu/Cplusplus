#ifndef TEN_TWO_H
#define TEN_TWO_H
#include <string>

// public和private可以多次使用，分开定义私有和共有成员
// 类的声明部分
class Stock {
  // 如果不声明构造函数，系统会隐式声明一个不进行任何其余操作的构造函数
  // 构造函数默认没有返回值，但也没有被声明为void，构造函数没有声明类型，名称就是类名称
public:
  // 重构无参数的默认构造函数
  Stock();
  // 自定义的构造函数
  Stock(const std::string &co, long n = 0, double pr = 0.0);
  ~Stock();
  // 不使用其他方法初始化私有变量
  // void acquire(const std::string &co, long n, double pr); /
  void bug(long num, double price);
  void sell(long num, double price);
  void update(double price);
  // const成员函数，确保这个函数内部不会修改私有成员变量
  // 如果构造类对象时，声明为const对象，则show能被执行，而其他函数编译器拒绝执行
  void show() const;

  // 使用this的成员函数
  const Stock &topval(const Stock &s) const;

  // 封装，外边无法直接使用
private: // private可以不写，默认私有
  std::string company;
  long shares;
  double share_val;
  double total_val;
  double profit = 0;
  // 私有函数，不给外部用，方便每次进行操作（调用共有方法）后自动确定total的值
  // 尽管没有写inline，但是定义在类声明中的函数都是内联函数
  // 类声明中常将短小的函数直接进行定义，让其称为内联函数
  void set_total() {
    total_val = shares * share_val;
  }
};

#endif