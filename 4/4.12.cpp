#include <iostream>

using namespace std;

struct inflatable {
  char name[20];
  float volume;
  double price;
};

int main(void) {
  inflatable ift = {"sunflowers", 0.20, 12.49};
  cout << "ift.name = " << ift.name << endl;
  cout << "ift.volume = " << ift.volume << endl;
  cout << "ift.price = " << ift.price << endl;

  inflatable choice; // 不初始化
  cout << "choice = ift; " << "进行结构赋值" << endl;
  choice = ift; // 结构体赋值，ift的数据会被拷贝到choice

  cout << "choice.name = " << choice.name << endl;
  cout << "choice.volume = " << choice.volume << endl;
  cout << "choice.price = " << choice.price << endl;

  // 在创建结构体的时候可以直接传递对应的结构体对象
  struct perks { // 这种时候结构体名称可以省略，是一个匿名结构体
    int key_number;
    char car[12];
  } my_car = {7, "Packard"};

  cout << "my_car.key_number = " << my_car.key_number << endl;
  cout << "my_car.car = " << my_car.car << endl;
  return 0;
}