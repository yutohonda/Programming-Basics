#include <iostream>

using namespace std;

int main()
{
    double input[5] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < 5; ++i)
    {
        cin >> input[i];
    }

    // 以下、どちらか好きな方を利用する
    //cout << average(input[0], input[1], input[2], input[3], input[4]) << endl;
    //cout << average(input, 5) << endl;
}
