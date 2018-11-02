#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// 二項分布
double Bin(int m, int M, double mu)
{
    // TODO: 完成させる
}

// コイントス関数
//  表が出る確率muの値は0.0～1.0の範囲
bool CoinToss(double mu)
{
    return rand() <= RAND_MAX * mu;
}

int main()
{
    int M;     // コインを投げる回数
    double mu; // コインを1回投げたときに表が出る確率mu

    cout << "コインを何回投げる？（正の整数）";
    cin >> M;
    cout << "コインの表が出る確率は？（0～1.0）";
    cin >> mu;
    for (int m = 0; m <= M; ++m)
    {
        cout << M << "回中" << m << "回表が出る確率は" << Bin(m, M, mu) << endl;
    }

    // シミュレーション
    double avgCount = 0;
    for (int trial = 0; trial < 1000; ++trial)
    {
        int count = 0;
        for (int i = 0; i < M; ++i)
        {
            if (CoinToss(mu))
            {
                ++count;
            }
        }
        avgCount += count;
    }
    cout << endl << "1000回のシミュレーション結果、表が出た回数は" << M << "回中" << avgCount / 1000.0 << "回" << endl;
}
