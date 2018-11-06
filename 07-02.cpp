#include <iostream>
#include <algorithm>

using namespace std;

// sincos関数を実装

int main(void)
{
    for (int angle = 0; angle <= 360; ++angle)
    {
        // ラディアンに変換（計算式を追加）
        double radian = 
        
        double sv = 0, cv = 0;
        sincos(sv, cv, radian);

        cout << sv << ", " << cv << endl;
    }
    return 0;
}
