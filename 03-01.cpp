#include <iostream>
using namespace std;
int main()
{
  int x = 30, y = 20;
  cout << x << "," << y << endl;

  // 正解例（あくまで一例）
  int z = x; // xの内容をいったんzにバックアップ
  x = y; // 安心してxをyの値で上書き
  y = z; // バックアップしておいたxの値でyを上書き

  cout << x << "," << y << endl;
}
