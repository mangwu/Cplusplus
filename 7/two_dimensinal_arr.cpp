#include <algorithm>
#include <iostream>

using namespace std;

// 二维数组的传递，如果传递数组名，传递的是一个指针，这个指针指向一个int[x]数组
// 所以定义时要把二维数组的列col表定义出来，表示指针指向的是int[col]的数组
// 加上括号表面定义的是一个ar指针，它指向一个int[4]数组
// 如果不加括号 int * ar[4]表示的是一个数组，数组中的每个元素都是int *类型的地址
int sum_two_d_array(int (*ar)[4], int row);
// int sum_tow_d_array(int ar[][4], int row); // 这样写也是正确的

int main(void) {
  int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {2, 4, 6, 8}};
  int b[100][4] = {1};
  fill(&b[0][0], &b[99][3] + 1, 1); // 全部元素设置为1
  int sum = sum_two_d_array(a, 3);  // 计算二维数组a的数组和
  cout << "sum of a = " << sum << endl;

  sum = sum_two_d_array(b, 100); // 计算二维数组b的数组和
  cout << "sum of b = " << sum << endl;

  sum = sum_two_d_array(b + 10, 20); // 计算第10行到第30行的元素和
  cout << "sum of b( row10 - row30 ) = " << sum << endl;

  int r;
  int c;
  cout << "输入r，0-99:";
  cin >> r;
  cout << "输入c，0-3：";
  cin >> c;
  cout << "设置b[" << r << "][" << c << "]=5" << endl;
  b[r][c] = 5;
  cout << "*(*(b + r) + c) = " << *(*(b + r) + c) << endl;
  // b是数组名，是指向第一个int[4]的指针
  // b+r是指向第r行的的int[4]的指针
  // *(b+r)是指向第r行的int[4]数组中第一个元素的指针
  // *(b+r)+c是指向第r行的int[4]数组中第c个元素的指针
  // *(*(b+r)+c)是第r行的intp[4]数组中的第c个元素

  return 0;
}

int sum_two_d_array(int (*ar)[4], int row) {
  int total = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < 4; j++) {
      total += ar[i][j];
    }
  }
  return total;
}