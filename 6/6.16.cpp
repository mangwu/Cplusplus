#include <cstdlib> // 定义了exit，EXIT_FAILURE
#include <fstream>
#include <iostream>

const int SIZE = 60;

using namespace std;
int main() {
  char filename[SIZE];
  ifstream inFile;
  cout << "输入数据文件的文件名:";
  cin.getline(filename, SIZE);
  inFile.open(filename);
  // 需要判断文件是否能打开
  if (!inFile.is_open()) {
    cout << "文件" << filename << "没有成功打开！\n";
    cout << "程序终止！\n";
    exit(EXIT_FAILURE);
  }
  double value;
  double sum = 0.0;
  int count = 0;

  inFile >> value;
  // good判断是否读取成功
  while (inFile.good()) {
    ++count;
    sum += value;
    inFile >> value;
  }

  // 是否文件尾
  if (inFile.eof()) {
    cout << "End of file reached.\n";
  } else if (inFile.fail()) {
    // 程序是否中断（例如读取的数据类型不匹配时）
    cout << "Input terminated by data mismatch.\n";
  } else {
    cout << "Input terminated for unknown reason.\n"; // 如磁盘损坏等
  }
  // count不能为0，否则无法进行相除
  if (count == 0) {
    cout << "No data!";
  } else {
    cout << "Items count:" << count << endl;
    cout << "Sum:" << sum << endl;
    cout << "Average: " << sum / count << endl;
  }

  return 0;
}