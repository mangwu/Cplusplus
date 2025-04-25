#include <iostream>

using namespace std;
// 两个程序员对同一个功能实现的算法运行代码的时间
double betsy(int lines);
double pam(int lines);
void estimate(int lines, double (*pf)(int));
int main(void) {
  int code; // 代码行数
  cout << "有多少行代码?" << endl;
  cin >> code;
  cout << "Betsy 的算法的计算需要的时间：\n";
  estimate(code, betsy);
  cout << "Pam 的算法的计算需要的时间：\n";
  estimate(code, pam);
  return 0;
}

double betsy(int lines) {
  return 0.05 * lines;
}

double pam(int lines) {
  return 0.03 * lines + 0.00004 * lines * lines; // 模拟的，不用在意
}

void estimate(int lines, double (*pf)(int)) {
  cout << lines << " lines will take ";
  cout << (*pf)(lines) << " second(s)" << endl;
}