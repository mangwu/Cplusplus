#include <iostream>

using namespace std;

// 函数模板的声明
template <typename T>
void ShowArr(T *arr, int n);

template <typename T>
void ShowArr(T **arr, int n);

struct debts {
  char name[50];
  double amount;
};

int main(void) {
  int things[6] = {13, 31, 103, 301, 310, 130};
  debts mr_E[3] = {
    {"Ima Wolfe", 2400.0},
    {"Ura Foxe", 1300.0},
    {"IUe Jgyhhg", 1800.0},
  };
  double *pd[3];
  for (int i = 0; i < 3; i++) {
    pd[i] = &mr_E[i].amount;
  }
  cout << "打印mr_E中的相关内容\n";
  // 使用templateA T => int
  ShowArr(things, 6);
  // 使用templateB T => double
  ShowArr(pd, 3);
  // 如果使用tA，会让T => double *，是更复杂的转换，不是最具体的，所以不使用
  return 0;
}

template <typename T>
void ShowArr(T *arr, int n) {
  cout << "templateA\n"; // 提示信息
  for (int i = 0; i < n; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}

template <typename T>
void ShowArr(T **arr, int n) {
  cout << "templateB\n"; // 提示信息
  for (int i = 0; i < n; i++) {
    cout << *arr[i] << '\t';
  }
  cout << endl;
}