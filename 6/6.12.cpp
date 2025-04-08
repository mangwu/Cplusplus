#include <iostream>

using namespace std;

int main(void) {
  char line[80];
  int spaces = 0;
  cout << "输入一行文本:\n";
  cin.get(line, 80);
  cout << "完整文本为:\n" << line << endl;
  cout << "接下来会打印第一句，并且计算空格数量!\n";
  for (int i = 0; line[i] != '\0'; i++) {
    cout << line[i];
    if (line[i] == '.')
      break; // 跳出循环，
    if (line[i] != ' ')
      continue; // 跳出本轮，继续下轮循环，不执行本轮循环体的后续语句
    spaces++;
  }
  if (spaces == 0)
    goto nospaces;
  // goto语句也是结构化控制语句用于控制程序流程，
  // 但是最好不要使用，会让代码结构不易理解，后期维护困难
  cout << "\n空格数量:" << spaces << endl;
  goto end;
nospaces:
  cout << "\n没有空格！" << endl;
end:
  return 0;
}