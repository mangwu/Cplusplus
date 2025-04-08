#include <cctype>
#include <iostream>
#include <unordered_map>

using namespace std;

string asciiCodeToChar(int i);
int main(void) {
  const int asciiCodeSize = 128;
  // cctype的所有函数介绍：参考 https://zh.cppreference.com/w/cpp/header/cctype

  // 10个数字，26个小写字母，26个大写字母 => 62个
  cout << "int isalnum( int ch ); " << "检查给定字符是否是字母数字字符："
       << "0-9,a-z,A-Z" << endl;

  // 26个小写字母,26个大写字母 => 52个
  cout << "int isalpha( int ch ); " << "检查给定字符是否是字母字符："
       << "a-z,A-Z" << endl;

  // 26个小写字母 => 26个
  cout << "int islower( int ch ); " << "检查给定字符是否是小写字母字符："
       << "a-z" << endl;

  // 26个大写字母 => 26个
  cout << "int isupper( int ch ); " << "检查给定字符是否是大写字母字符："
       << "A-Z" << endl;

  // 10个数字 => 10个
  cout << "int isdigit( int ch ); " << "检查给定字符是否是数字字符："
       << "0-9" << endl;

  // 0-9表示十六进制的前10个数字，a-f/A-F表示十六进制的后6个数字 => 22
  cout << "int isxdigit( int ch ); " << "检查给定字符是否是十六进制数字字符："
       << "0-9,a-f,A-F" << endl;

  // 控制字符包括前32个ASCII字符和最后一个字符 => 33个
  cout << "int iscntrl( int ch ); " << "检查给定字符是否是控制字符："
       << "编码为0x00-0x1f(0-31)，0x7f(127)的字符" << endl;

  // 10个数字，26个小写字母，26个大写字母，32个标点符号(不包括空格) => 94个
  cout << "int isgraph( int ch ); " << "检查给定字符是否是图形字符："
       << "包括数字(0-9)，大写字母(A-Z)，小写字母(a-z)，"
       << "标点符号(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)" << endl;

  // 空格，换页，换行，回车，和两个方向的制表符 =>
  // 6个(除了空格，剩余5个属于控制字符)
  cout << "int isspace( int ch ); " << "检查给定字符是否是空白间隔字符："
       << "空格(0x20),换页(0x0c,\\f),换行(0x0a,\\n),回车(0x0d\r)"
       << "水平制表符(0x09,\\t),垂直制表符(0x0b\\v)" << endl;

  // 空格和水平制表符=>2个
  cout << "int isblank( int ch ); " << "检查给定字符是否是空白字符："
       << "空格(0x20),水平制表符(0x09,\\t)" << endl;

  // 10个数字，26个小写字母，26个大写字母，32个标点符号,一个空格 => 95个
  cout << "int isprint( int ch ); " << "检查给定字符是否是可打印字符："
       << "包括数字(0-9)，大写字母(A-Z)，小写字母(a-z)，空格(0x20)"
       << "标点符号(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)" << endl;

  // 32个标点符号(不包括空格) => 32个
  cout << "int ispunct( int ch ); " << "检查给定字符是否是标点符："
       << "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~" << endl;

  cout << "dec\thex\tchar or escape\t";
  cout << "isalnum\tisalpha\tislower\tisupper\tisdigit\tisxdigit\t";
  cout << "iscntrl\tisgraph\tisspace\tisblank\tisprint\tispunct\t";
  cout << endl;
  for (int i = 0; i < asciiCodeSize; i++) {
    cout << dec << i << "\t0x";           // 十进制展示ascii码
    cout << hex << i << "\t";             // 十六进制展示ascii码
    cout << asciiCodeToChar(i) << "\t\t"; // 展示可显示的字符
    cout << dec << isalnum(i) << "\t";    // 是否是字母数字字符
    cout << isalnum(i) << "\t";           // 是否是字母字符
    cout << islower(i) << "\t";           // 是否是小写字母字符
    cout << isupper(i) << "\t";           // 是否是大写字母字符
    cout << isdigit(i) << "\t";           // 是否是数字字符
    cout << isxdigit(i) << "\t\t";        // 是否是数字字符
    cout << iscntrl(i) << "\t";           // 是否是控制字符
    cout << isgraph(i) << "\t";           // 是否是图形字符
    cout << isspace(i) << "\t";           // 是否是空白间隔字符
    cout << isblank(i) << "\t";           // 是否是空白字符
    cout << isprint(i) << "\t";           // 是否是可打印字符
    cout << ispunct(i) << "\t";           // 是否是标点符号
    cout << endl;
  }

  cout << "int tolower( int ch ); "
       << "转换字符为小写，返回对应的小写字符的ASCII码:"
       << "只转换A-Z共26个英文字符，其它字符不做修改返回" << endl;

  cout << "int toupper( int ch ); "
       << "转换字符为大写，返回对应的小写字符的ASCII码:"
       << "只转换a-z共26个英文字符，其它字符不做修改返回" << endl;

  char a = 'a';
  char A = 'A';
  char comma = ',';

  cout << "char A = " << A << "\ttolower(A) = " << tolower(A)
       << "\t\tchar(tolower(A)) = " << char(tolower(A)) << endl;
  cout << "char a = " << a << "\ttoupper(a) = " << toupper(a)
       << "\t\tchar(toupper(a)) = " << char(toupper(a)) << endl;
  cout << "char comma = " << comma << "\ttolower(comma) = " << tolower(comma)
       << "\ttoupper(comma) = " << toupper(comma)
       << "\tchar(toupper(comma)) = " << char(toupper(comma))
       << "\tchar(tolower(comma)) = " << char(tolower(comma)) << endl;
  return 0;
}

string asciiCodeToChar(int i) {
  if (i >= 32 && i <= 126) {
    string str(1, (char)(i));
    return str;
  }
  unordered_map<int, string> map = {
    {0, "\\0"},    {1, "\\x01"},  {2, "\\x02"},   {3, "\\x03"},  {4, "\\x04"},
    {5, "\\x05"},  {6, "\\x06"},  {7, "\\a"},     {8, "\\b"},    {9, "\\t"},
    {10, "\\n"},   {11, "\\v"},   {12, "\\f"},    {13, "\\r"},   {14, "\\x0e"},
    {15, "\\x0f"}, {16, "\\x10"}, {17, "\\x11"},  {18, "\\x12"}, {19, "\\x13"},
    {20, "\\x14"}, {21, "\\x15"}, {22, "\\x16"},  {23, "\\x17"}, {24, "\\x18"},
    {25, "\\x19"}, {26, "\\x1a"}, {27, "\\x1b"},  {28, "\\x1c"}, {29, "\\x1d"},
    {30, "\\x1e"}, {31, "\\x1f"}, {127, "\\x7f"},
  };
  if (map.count(i))
    return map[i];
  return " ";
}