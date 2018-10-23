#include <iostream>
using namespace std;
int main()
{
  // 七つの値を中かっこ{ }内にカンマ , 区切りで記述
  double a[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, -7.0};
  // a[0] から a[6] の値を全て足し算
  double sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
  // 出力
  cout << sum << endl;
}
