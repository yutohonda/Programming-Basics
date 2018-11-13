#include <iostream>
#include <cmath> // 数学関数を収めたヘッダファイル

using namespace std;

int main()
{
    // 1.  9234893.0　の平方根
    cout << sqrt(9234893.0) << endl; //平方根を求めるのはsqrt関数
    // 2.  2349.0　の自然対数
    cout << log(2349.0) << endl;     //自然対数log関数
    // 3.  3.1　の　1.6乗
    cout << pow(3.1, 1.6) << endl;   // べき乗はpow関数
    // 4.  sin(28.3)[degree]　←単位に注意
    double degree = 28.3;            // 角度（°）
    double radian = degree * 3.141592 / 180.0; // 角度をラジアンに変換
    cout << sin(radian) << endl;     // 正弦関数 sin の引数はラジアンなので適切な値を指定
    // 5.  ｰ20 ~30 の整数の絶対値の和　← for文利用
    int sum = 0; // 総和を表す変数
    // 変数iを-20から+30まで1つずつ増やす
    for (int i = -20; i <= 30; ++i) // 「<=」となっている点に注意
    {
    	sum = sum + abs(i); // 絶対値関数 abs を用いて i の絶対値をsumに足し合わせる
    }
    cout << sum << endl;
}
