#include <iostream>

using namespace std;

int main()
{
    // アプローチ：3つの変数の大小関係をチェックし、
    // 適切な順番で出力するためのコードを実行する
    
    // キーボード（下のStdin）から3つの整数を取得
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a >= b && b >= c) // a >= b >= c なら
    {
        cout << a << " " << b << " " << c << endl;
    }
    else if (a >= c && c >= b) // a >= c >= b なら
    {
        cout << a << " " << c << " " << b << endl;
    }
    else if (b >= a && a >= c) // b >= a >= c なら
    {
        cout << b << " " << a << " " << c << endl;
    }
    else if (b >= c && c >= a) // b >= c >= a なら
    {
        cout << b << " " << c << " " << a << endl;
    }
    else if (c >= a && a >= b) // c >= a >= b なら
    {
        cout << c << " " << a << " " << b << endl;
    }
    else // c >= b >= a なら
    {
        cout << c << " " << b << " " << a << endl;
    }
}