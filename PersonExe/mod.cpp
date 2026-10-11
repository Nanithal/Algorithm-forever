// 这是测试取模运算的性质的cpp文件】
#include <iostream>
using namespace std;
int main()
{

    // c++和java中，取模运算即是先按照正数算出一个结果，然后符号取自于被除数（即分子6）
    int a, b;
    a = 9, b = 8;
    cout << a % b << endl;
    b = -8;
    cout << a % b << endl;
    b = -10;
    cout << a % b << endl;
    a = -11;
    cout << a % b << endl;
    return 0;
}