#include <iostream>
const int ArrSize = 8;

int sum_arr(const int *, const int *);
void show_arr(const int *, int);

using namespace std;

int main(void) {
  int cookies[ArrSize] = {1, 2, 3, 4, 7, 8, 9, 12};
  show_arr(cookies, ArrSize);
  int sum = sum_arr(cookies, cookies + ArrSize);
  cout << "total sum = " << sum << endl;
  sum = sum_arr(cookies, cookies + 3);
  cout << "first three sum = " << sum << endl;
  sum = sum_arr(cookies + 4, cookies + 8);
  cout << "last four sum = " << sum << endl;
  return 0;
}

int sum_arr(const int *begin, const int *end) {
  int sum = 0;
  for (const int *pt = begin; pt < end; pt++) {
    sum += (*pt);
  }
  return sum;
}

void show_arr(const int *arr, int size) {
  cout << "{";
  for (int i = 0; i < size; i++) {
    if (i < size - 1) {
      cout << arr[i] << ", ";
    } else {
      cout << arr[i] << "}\n";
    }
  }
}