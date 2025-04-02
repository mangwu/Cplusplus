#include <iostream>
#include <vector>
const int ArrSize = 10;

using namespace std;
int main(void) {
  vector<int> nums;
  cout << "输入一些（最多10个）正数，如果输入负数就会提前停止\n";
  int temp;
  cout << "First Value:";
  cin >> temp;
  int i = 0;
  while (temp >= 0 && i < ArrSize) {
    nums.push_back(temp);
    i++;
    if (i < ArrSize) {
      cout << "Next Value:";
      cin >> temp;
    }
  }
  if (i == 0) {
    cout << "No Data\n";
  } else {
    cout << "输入比较数：";
    cin >> temp;
    int count = 0;
    for (int num : nums) {
      if (num > temp) {
        count++;
      }
    }
    cout << "有" << count << "个元素比" << temp << "大" << endl;
  }
  return 0;
}