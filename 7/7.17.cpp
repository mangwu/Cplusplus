#include <iostream>

using namespace std;
const int Len = 66;
const int Divs = 6;
void subdivide(char *ruler, int low, int high, int level);
int main(void) {
  char ruler[Len];
  ruler[Len - 1] = '\0';
  int max = Len - 2;
  int min = 0;
  ruler[min] = ruler[max] = '|';
  for (int i = 1; i < max; i++) {
    ruler[i] = ' ';
  }
  for (int i = 1; i <= 6; i++) {
    subdivide(ruler, min, max, i);
    cout << ruler << endl; // 每次打印一行
    // 书中还把ruler的中间值全部还原为空格字符了，实际上没必要
  }
  return 0;
}

void subdivide(char *ruler, int low, int high, int level) {
  if (level == 0) {
    return;
  }
  int mid = (low + high) / 2;
  ruler[mid] = '|';
  subdivide(ruler, low, mid, level - 1);
  subdivide(ruler, mid, high, level - 1);
}