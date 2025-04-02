#include <iostream>

using namespace std;

const char *bmiCategory[4] = {
  "偏瘦，营养不良、免疫力低",
  "正常，健康风险低",
  "超重，心血管疾病风险增加",
  "肥胖，多种慢性疾病风险",
};

int main(void) {
  double BMI;
  double weight;
  double height;
  cout << "输入体重（kg）:\n";
  cin >> weight;
  cout << "输入身高（cm）:\n";
  cin >> height;
  BMI = weight / (height * height / 10000);
  int index;
  // &&符号用于确定取值范围
  if (BMI < 18.5) {
    index = 0;
  } else if (BMI >= 18.5 && BMI <= 24.9) {
    index = 1;
  } else if (BMI > 24.9 && BMI <= 29.9) {
    index = 2;
  } else if (BMI > 29.9) {
    index = 3;
  }
  cout << "你的BMI值数是：" << BMI << endl;
  cout << "检测结果是:" << bmiCategory[index] << endl;
  return 0;
}