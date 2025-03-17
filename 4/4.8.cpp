#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s1 = "penguin";
  string s2, s3;

  cout << "s1 = " << s1 << endl;
  cout << "将s2赋值为s1： s2 = s1;" << endl;
  s2 = s1; // 字符串对象可以这样赋值（字符数组不行）
  cout << "s2 = " << s2 << endl;
  cout << "s2 == s1 ? " << (s2 == s1) << endl;
  cout << "s2可以重新用C风格的字符串（字面量）进行赋值: s2 = \"buzzard\";"
       << endl;
  s2 = "buzzard";
  cout << "s2 = " << s2 << endl;
  cout << "将s1和s2拼接后赋值给s3：s3 = s1 + s2;" << endl;
  s3 = s1 + s2;
  cout << "s3 = " << s3 << endl;
  cout << "将s1后追加拼接s2：s1 += s2;\n";
  s1 += s2;
  cout << "s1 = " << s1 << endl;
  cout << "将s1后还可以直接追加C风格字符串(字面量)：s1 += \" for a day\";\n";
  s1 += " for a day";
  cout << "s1 = " << s1 << endl;
  return 0;
}