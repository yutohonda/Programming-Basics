#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 5; ++i) // 中括弧{ }内の処理を5回繰り返す
    {
        double x;
        cin >> x;                // データを受け取って
        cout << x * 2.0 << endl; // 2倍して出力する
    }
}

// 別解
int main()
{
    double data[5];
    for (int i = 0; i < 5; ++i)
    {
        cin >> data[i];          // 配列の各要素に先頭から順に入力
    }
    for (int i = 0; i < 5; ++i)
    {
        data[i] = data[i] * 2.0; // 配列の各要素を先頭から順に2倍
    }
    for (int i = 0; i < 5; ++i)
    {
        cout << data[i] << endl; // 配列の各要素を先頭から順に出力
    }
}
