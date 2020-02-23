// https://www.acmicpc.net/problem/2690
// Math3 (4) 최공 최약
// NUMBER 2690

//

#include <iostream>
using namespace std;

#define endl "\n"

int GetLcm(int _gcd, int a, int b)
{
    return a * b / _gcd;
}

int GetGcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GetGcd(b, a % b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int gcd = GetGcd(a, b);
    cout << gcd << endl;
    cout << GetLcm(gcd, a, b) << endl;

    return 0;
}