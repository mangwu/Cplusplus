#include <string>

// string库里不仅仅包含string类，还有其他不同类型的字符串类，以及一些函数
using namespace std;

int main(void) {
  // 函数：
  // 1.之前学过的getline就是string库里的，用于处理一行字符串的输入:
  string str;
  // input getline(input, str, delim);
  // a. input是输入流，cin就是istream类型的输入流对象
  // b. str放置数据的目标字符串，通常为string类型
  // c. delim是分隔符，默认为换行符，用于判断停止输入标识
  getline(cin, str, '\n');

  // 2.常用的字符串数值转换函数
  str = "123";
  // stoi
  cout << stoi(str) << endl;

  return 0;
}