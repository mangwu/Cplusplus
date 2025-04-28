#include <iostream>
#include <string>
using namespace std;
struct free_throws {
  string name;
  int made;
  int attempts;
  float percent;
};
void set_pc(free_throws &ft);
void display(const free_throws &ft);
free_throws &accumulate(free_throws &ft1, const free_throws &ft2);
// const free_throws &clone2(free_throws &ft);
const free_throws &clone(free_throws &ft);
int main(void) {
  free_throws one = {"ZMJJKK", 13, 14};
  free_throws two = {"Andor Knott", 10, 16};
  free_throws three = {"Minnie Max", 7, 9};
  free_throws four = {"Long Long", 5, 9};
  free_throws five = {"CHIOO CHIOO", 6, 14};
  free_throws team = {"Throwgoods", 0, 0};
  free_throws dup;

  // 设置百分比
  set_pc(one);
  set_pc(two);
  set_pc(three);
  set_pc(four);
  set_pc(five);
  // 展示成绩
  display(one);

  // 计算和
  accumulate(team, one);
  display(team);
  // 这里accumulate返回的是team的引用，所以可以直接传递给display
  display(accumulate(team, two));

  // 同理accumulate返回的是team的引用，也可以直接传递给接受team引用的accumulate
  accumulate(accumulate(team, three), four);
  display(team);

  // dup是另外一个不同的结构体对象，结构体的直接赋值是按值传递的
  // 注意dup不是team的引用，它拥有自己的内存空间
  dup = accumulate(team, five);
  team.attempts = 100;
  set_pc(team);
  display(dup);

  // 函数返回的对象引用变量实际上就是对象变量本身：
  accumulate(dup, five) = four;
  // 常规函数（按值传递按值返回），返回的是一个右值，但是引用不一样，它是左值
  // 赋值语句左边必须是一个可修改的左值，这里引用是一个可修改内存块，所以可以被赋值
  // 如果你不想要被返回的引用不允许被更改，可以给返回类型加上const，不可修改的左值
  display(dup);
  return 0;
}

// 使用引用会影响到外部传递的结构体内容
void set_pc(free_throws &ft) {
  if (ft.attempts) { // 要判断attempts除数不能为0
    ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
  } else {
    ft.percent = 0.0f;
  }
}
// 显示数据不用修改，使用const
void display(const free_throws &ft) {
  cout << "name\t\t" << ft.name << endl;
  cout << "made\t\t" << ft.made << endl;
  cout << "attempts\t" << ft.attempts << endl;
  cout << "percent\t\t" << ft.percent << "%" << endl;
}

free_throws &accumulate(free_throws &ft1, const free_throws &ft2) {
  ft1.attempts += ft2.attempts;
  ft1.made += ft2.made;
  set_pc(ft1);
  return ft1;
}

// 返回引用的错误写法
// const free_throws &clone2(free_throws &ft) {
// free_throws newguy; // newguy在函数中声明
// newguy = ft;        // 按值传递，ft的内容复制了一份到newguy中
// return newguy;      // 这里编译会报错，
// }
// 因为newguy是local variable，函数执行完毕后就没了,返回的引用从哪里找它呢？
// 既然在函数newguy开辟的内存空间会被回收，为啥之前可以直接返回结构体呢？
// 1.因为直接返回结构体对象是按值传递， 它的返回值会被复制到一个临时位置，
//   然后被赋值给在其他上下文接受它变量，（所以消耗更大）
// 2.但是引用不同，因为引用就是外部定义的变量的别名，直接返回给定义变量的外部
//   不用担心被回收，因为引用的内存空间是在外部作用域被开辟的，
//   也不需要复制到一个临时位置，直接按照引用的内存空间复制给接受它的变量即可
// 3.我们之前学过的new关键字开辟的内存空间是程序员主动开辟的，一直存在，
//   不会被函数主动释放掉，所以可以被作为返回值返回，
//   这也间接解释了为什么new之后，程序员要主动的delete自己开辟过的内存空间

// 隐式调用new，下面代码可以编译通过并使用
const free_throws &clone(free_throws &ft) {
  free_throws *pt; // 定义pt指针的时候会隐式使用new开辟内存空间
  *pt = ft;        // 这里按值赋值，会进行copy操作
  return *pt; // *pt是一个隐式new出来的内存空间，返回出去后能作为结构体引用的值别引用
}
// 这个方法的安全问题也有：delete删除隐式new开辟的内存空间容易被忽视