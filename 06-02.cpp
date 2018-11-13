#include <iostream>

using namespace std;

// 先頭の「double」が指す意味＝計算結果をdouble型として戻す関数（ここでは平均値）
//
// 1. 5つのdouble型の値を受け取って、その平均値を戻す関数
// 5つの変数名は何でもよいので、ここではa～eとしている
double average1(double a, double b, double c, double d, double e)
{
	// a～eを全て足し、5で割ることで平均値を求める
	// その計算結果として得られる1つの値をreturnで戻す
	return (a + b + c + d + e) / 5.0;
}

// 2. 配列を引数とする場合：　n個の値が入った配列を受け取り、
// その要素の平均値をdouble型で戻す
double average2(double a[], int n)
{
	// まずn個の値の総和をfor分を用いて計算
	double sum = 0;
	for (int i = 0; i < n; ++n)
	{
		sum = sum + a[i];
	}
	return sum / n; // 総和をn個で割り算して平均値を求め、return で戻す
}

int main()
{
    double input[5] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < 5; ++i)
    {
        cin >> input[i];
    }

    // 以下、どちらか好きな方を利用する
    cout << average1(input[0], input[1], input[2], input[3], input[4]) << endl;
    cout << average2(input, 5) << endl;
}
