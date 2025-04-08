#include <iostream>

using namespace std;

enum { alarm = 1, report, alibi, comfort, quit };

void showMenu();
void reportFnc();
void comfortFunc();
void endGame();

int main(void) {
  showMenu();
  int choice;
  cin >> choice;
  while (choice != quit) {
    switch (choice) {
      case alarm:
        cout << "警告!\a警告!\a警告\a\n";
        break;
      case report:
        reportFnc();
        break;
      case alibi:
        cout << "不准逃跑！\n";
        cout << "不准逃跑！\n";
        cout << "不准逃跑！\n";
        break;
      case comfort:
        comfortFunc();
        break;
      default:
        cout << "输入不合法\a\n";
    }
    cout << "\n";
    showMenu();
    cin >> choice;
    cout << "\n";
  }
  endGame();
  return 0;
}

void showMenu() {
  cout << "输入数字1,2,3,4,5选择：\n";
  cout << "1) alarm\t\t2) report\n"
          "3) alibi\t\t4) comfort\n"
          "5) quit\n";
}

void reportFnc() {
  cout << "\n你选择了report！\n"
       << "...\n"
       << "报告完毕!!" << endl;
}
void comfortFunc() {
  cout << "\n你选择了comfort！\n"
       << "...\n"
       << "奖励完毕!!!" << endl;
}

void endGame() {
  cout << "\n退出程序,Bye!!!";
}