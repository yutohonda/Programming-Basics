#include <iostream>
using namespace std;
int main()
{    
    double r;
    double pi = 3.1415;
    cin >> r;
    double v = (4 * pi * r * r * r )/ 3;
    double s = 4 * pi * r * r;
    
    if (s == v){
    cout << "equal!" << endl;
    }
    
    else if (s > v){
    cout << "area is larger than volume" << endl;;
    }
    
    else if (v > s){
    cout << "area is smaller than volume" << endl;
    }

}
