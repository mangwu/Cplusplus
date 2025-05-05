#include <iostream>

// pal变量定义在全局名称空间中
int pal = 0;
// 名称空间可以是全局的
namespace Jack {
double pail;
int pal;
int mk;
}; // namespace Jack

// 名称空间可以位于另一个名称空间中，但是不能位于代码块中
namespace Jill {
void goose(const char *str);
double bucket;
int pal;
namespace Jeff {
int pal;
};
}; // namespace Jill

// 名称空间可以分开声明定义成员
namespace Jill {
void goose(const char *str) {
  std::cout << str << std::endl;
}
}; // namespace Jill

// 可以在名称空间里使用using引入其他名称空间的名称
namespace Jaff {
using Jack::mk;
using Jill::pal;
}; // namespace Jaff

// 名称空间可以通过namespace创建别名
namespace my_very_favorite_things {
int k;
};
namespace mvft = my_very_favorite_things; // mvft是一个别名
// 通过别名可以减少嵌套
namespace JJ = Jill::Jeff;

// 未命名的名称空间，就跟使用using编译指令一样
// 因为它没有名称，它只能在当前文件使用，相当于多个全局静态的变量
namespace {
int ice;
int bandycoot;
} // namespace

int main(void) {
  // 不同名称空间中的名称不会发生冲突
  // 但是同一个名称空间中要符合单定义规则

  // 使用作用域解析符::访问名称空间中的名称
  Jack::pal = 2;
  Jill::pal = 4;
  Jill::Jeff::pal = 6;
  // 使用不同名称空间中的变量
  std::cout << pal << " ," << Jack::pal << " ," << Jill::pal << " ,"
            << Jill::Jeff::pal << std::endl;
  Jill::goose("abc");
  // 有时候名称空间中的名称很多，我们要多次使用，可以使用using简化对名称的访问
  // 1.using声明：将名称空间的特定名称拿出来添加到当前声明区域中
  using Jill::goose; // 把goose拿出来，以后直接使用
  using Jill::pal;   // 把pal拿出来，以后直接使用，覆盖全局的变量
  using std::cout;
  using std::endl;
  // int pal = 5;       // 错误，会出现二义性
  goose("def");
  goose("hijk");
  // 访问全局的pal，可以使用::
  cout << "Jill 'pal:" << pal << endl;
  cout << "Global 'pal:" << ::pal << endl;

  // 2.using编译指令使得所有名称在当前声明区域都可用，用法如下
  using namespace Jack; // Jack中的名称在当前函数作用域中可以用了
  pail = 2.3;
  cout << "pail = " << pail << endl;

  // using的使用会增加名称冲突的可能性
  // using Jack::pal;  // 声明此句，编译会报错

  // 这是哪个名称空间的pal?，我们难以判断，因为Jack中也有pal，
  // 我们之前也声明了Jill的pal，但是这里应该会使用Jill中的pal
  // 因为使用using namespace Jack只是声明了名称空间，让Jack中的更容易访问
  // 并没有显示的声明Jack中的pal，所以不会发生冲突，pal仍然是从Jill拿来的
  pal = 5;
  cout << "pal = " << pal << endl;
  cout << "::pal = " << ::pal << endl;
  cout << "Jack::pal = " << Jack::pal << endl;
  cout << "Jill::pal = " << Jill::pal << endl;
  cout << "Jill::Jeff::pal = " << Jill::Jeff::pal << endl;

  // 下面的例子能更好的理解这句话
  // "使用using namespace Jack只是声明了名称空间，让Jack中的更容易访问"
  // Jack中有mk，但是当前区域还未主动声明定义mk
  int mk = 3; // 我们可以主动定义mk去隐藏Jack中的mk
  Jack::mk = 12;
  cout << mk << endl;
  cout << Jack::mk << endl;
  cout << Jaff::mk << endl;

  cout << JJ::pal << endl;

  return 0;
}