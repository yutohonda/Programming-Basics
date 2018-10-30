#include <iostream>

using namespace std;

int main()
{
    double pi = 3.14; // 円周率PIを設定しておく
    double r = 0; // 球の半径radius
    cin >> r;     // キーボード（wandboxは下記のstdin）から半径を取得
    
    // 球の表面積（小数点以下もあり得るので4ではなく4.0）
    double area = 4.0 * pi * r * r; 
    // 球の体積（先頭を 4 / 3 とすると、整数型の計算となり 4/3-->1となってしまう）
    double volume = 4.0 / 3.0 * pi * r * r * r;
    
    if (area == volume) // 表面積(area)と体積(volume)が等しい(==)なら…
    {
        cout << "Equal!" << endl;
    }
    else if (area > volume) // 表面積が体積より大きい（>）なら…
    {
        cout << "Area is larger." << endl;
    }
    else // if (volume > area) を付けてもよいが、この場合は自明なので省略可
    {
        cout << "Volume  is larger." << endl;
    }
}