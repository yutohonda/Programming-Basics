#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // 20個の乱数を格納した配列
    int array[20];
    for (int i = 0; i < 20; ++i)
    {
        array[i] = rand();
    }
    
    // TODO: 以降，必要なコードを追加
    for (int i = 0; i < 20; ++i)  // 20個のデータを1つずつ先頭から順にチェック
    {
        if (array[i] % 2 == 0 || array[i] % 3 == 0) // 2もしくは3で割り切れるなら
        {
            cout << array[i] << endl; // 出力
        }
    }  
}
