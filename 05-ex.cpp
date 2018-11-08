#include <iostream>
#include <cstdlib>
#include <algorithm> // 解2の場合に必要

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

    // 解1. バブルソート
    for (int i = 0; i < 19; ++i)
    {
        for (int j = i + 1; j < 20; ++j)
        {
            if (array[i] > array[j])
            {
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
    
    // 解2. STLのsort
    sort(array, array + 20);
    
    for (int i = 0; i < 20; ++i)
    {
        cout << array[i] << endl;
    }
}
