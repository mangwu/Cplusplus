#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  char cats[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'}; // C风格的字符串，以字符数组表示，结尾为'\0'空字符
  // cout << endl;
  cout << "cats =" << cats << endl;
  char bird[11] = "Mr. Cheeps"; // 字符串字面量的写法声明字符串，结尾隐式的包含\0，所以长度为11
  char fish[] = "Bubbles";      // 所以定义字符串时不写比较好，让编译器自己计算
  char boss[8] = "Bozo";        // 字符串的长度是按照结尾空字符来计算的，不是按照声明时填入的数组长度决定
  // 字符串的拼接，任何两个由空白分隔的字符串常量都会自动拼接为一个
  cout << "boss"
          " = "
       << boss << endl;

  const int Size = 15;
  char names1[Size];
  char names2[Size] = "C++owboy"; // 字符串常量
  cout << "names2 = " << names2 << endl;
  cout << "给未初始化的names1赋值：\n";
  cin >> names1;
  cout << "names1的长度:" << strlen(names1) << endl;
  cout << "names1存储在" << sizeof(names1) << " bytes长度的char数组中" << endl;
  cout << "names1[0] = " << names1[0] << endl;

  // 修改下标赋值为空可以控制字符数组的长度
  names2[3] = '\0';
  cout << "names2[3] = '\\0'后，names2的长度和实际字符串：" << strlen(names2) << "," << names2 << endl;
  return 0;
}