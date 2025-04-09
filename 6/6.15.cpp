#include <fstream>  // ifstream ofstream 文件输入输出流
#include <iostream> // input output stream 处理字节输入输出流

// cin 是istream的对象 cout是ostream的对象，它们都在std命名空间中
// ifstream ofstream类在std命名空间中
using namespace std;

int main(void) {
  char automobile[50]; // 用于存储汽车的型号信息等
  int year;
  double a_price;
  double d_price;

  cout << "输入汽车的品牌和型号\n";
  cin.getline(automobile, 50); // 使用cin的成员方法读取字符串
  cout << "输入汽车出厂日期\n";
  cin >> year;
  cout << "输入原始的出厂报价\n";
  cin >> a_price;

  d_price = 0.913 * a_price; // 折扣价格计算

  // 控制台输出
  cout << fixed;     // 定点模式设置
  cout.precision(2); // 浮点精度
  cout.setf(ios_base::showpoint);
  cout << "品牌和型号：" << automobile << endl;
  cout << "出厂日期:" << year << endl;
  cout << "出厂报价:" << a_price << endl;
  cout << "折扣价格:" << d_price << endl;

  // 文件流输出
  ofstream outFile;            // 创建一个文件输出流对象
  outFile.open("carinfo.txt"); // 将文件和文件输出流对象关联起来

  // 如果没有创建carinfo.txt文件，会自动在当前目录创建它
  // 如果已经创建就会直接打开，并且覆盖输入（会清除文件已有的字符）

  // 在文件中输入字符，其使用方法和cout相同
  outFile << fixed;
  outFile.precision(2); // 浮点精度
  outFile.setf(ios_base::showpoint);
  outFile << "品牌和型号：" << automobile << endl;
  outFile << "出厂日期:" << year << endl;
  outFile << "出厂报价:" << a_price << endl;
  outFile << "折扣价格:" << d_price << endl;

  // 关闭文件关联
  outFile.close();

  return 0;
}
