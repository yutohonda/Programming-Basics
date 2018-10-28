#include <iostream>
using namespace std;
int main()
{
    double target = 611;
    
    double x;
    cin >> x;
    
    int shimo1 = x/10;
    int shimo2 = x/100;
    
    cout << "あなたの答え:" << x << endl;
    cout << "" << endl;
    
    //答えが大きい数字なので大小関係で細かくコメントが出るようにしました。
    if (x < 0){
        cout << "負の数ではありません！" << endl;
    }
    else if (x < 10){
        cout << "もっともっと大きい数です！" << endl;
    }
    else if (x < 100 ){
        cout << "もっと大きい数です！" << endl;
    }
    

    else if (x < 600 ){
        cout << "桁はあってます！これより大きい数です！" << endl;
    }
    else if (x == target ){
        cout << "正解です！" << endl;
    }
    else if (610 <= x && x <= 612  ){
        cout << "あと一歩です！！！！" << endl;
    }
    else if (600 < x && x < 620  ){
        cout << "もうちょっとです！" << endl;
    }
    else if (x < 700 ){
        cout << "そうです！600代の数字です！" << endl;
    }
    else if (x == 777){
        cout << "そんなんじゃないです" << endl;
    }
    else if (x < 1000 ){
        cout << "桁はあってます！これより小さい数です！" << endl;
    }
    else if (x < 10000 ){
        cout << "行き過ぎです！" << endl;
    }
    else if (x == 19970611 ){
        cout << "月日でお願いします！" << endl;
    }
    else{
        cout << "そんなにでかくないです（笑）" << endl;
    }
    
    //追加コメント
    //合っている部分をintの性質を利用して教えるようにしました
    if (x == target){
        cout << "ちなみに6月11日は僕の誕生月日です！（照）" <<endl;
        
    }
    else if (x - shimo2 * 100 == 11){
        cout << "ちなみに下二桁合ってます！！" << endl;
    }
    else if (x - shimo1 * 10 == 1){
        cout << "ちなみに一の位は合ってます！！" << endl;
    }
    else if (10 <= x - shimo2 * 100 && x - shimo2 * 100 < 20){
        cout << "ちなみに十の位は合ってます！！" << endl;
    }
}
