#include <iostream>
using namespace std;

enum { red, orange, yellow, green, blue, violet, indigo, quit };

int main(void) {
  int code;
  bool flag = true;
  do {
    cout << "输入color code(0-6)，退出请输入7:\n";
    cin >> code;
    switch (code) {
      case red:
        cout << "red" << endl;
        break;
      case orange:
        cout << "orange" << endl;
        break;
      case yellow:
        cout << "yellow" << endl;
        break;
      case green:
        cout << "green" << endl;
        break;
      case blue:
        cout << "blue" << endl;
        break;
      case violet:
        cout << "violet" << endl;
        break;
      case indigo:
        cout << "indigo" << endl;
        break;
      case quit:
        cout << "Bye";
        flag = false;
        break;
      default:
        cout << "输入不合法" << endl;
        break;
    }
  } while (flag);

  return 0;
}