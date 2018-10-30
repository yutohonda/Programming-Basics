#include <iostream>

using namespace std;

int main()
{
    // アプローチ：変数a, b, cの順に降順になるように並び替える
    // その際、最初に最小値をcに移動させ、その後、b に2番目に小さい数
    // aに一番大きな数が入るように操作する
    
    // キーボード（下のStdin）から3つの整数を取得
    int a, b, c;
    cin >> a >> b >> c;
    
    int z; // 並び替え作業用
    if (a < b)
    {
        z = a;
        a = b;
        b = z;
    }
    if (b < c)
    {
        z = b;
        b = c;
        c = z;
    }
    // ここまでの操作で一番小さい数がcに入るので、cは固定する
    
    // あとはaとbの大小関係をチェックするだけ
    if (a < b)
    {
        z = a;
        a = b;
        b = z;
    }
    
    cout << a << " " << b << " " << c << endl;
}