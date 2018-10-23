#include <iostream>
using namespace std;
int main()
{
  double v0[2] = {11.0, 10.0};
  double v1[2] = {5.0, 7.0};
  double sum[2];
  
  // 解答例
  sum[0] = v0[0] + v1[0];
  sum[1] = v0[0] + v1[1];

  cout << sum[0] << "," << sum[1] << endl;
}
