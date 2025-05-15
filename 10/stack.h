#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item; // 方便做替换

class Stack {
private:
  // 枚举不是类的常量，所以可以直接使用
  enum { MAX = 10 };
  Item items[MAX];
  int top; // 假设top是栈顶指针
public:
  Stack(); // 默认构造函数，空栈
  bool isempty() const;
  bool isfull() const;
  bool push(const Item &item);
  bool pop(Item &item);
};

#endif