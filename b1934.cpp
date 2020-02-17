// https://www.acmicpc.net/problem/1934
// NUMBER 1934 최소공배수
//
// 두 자연수 A,B의 최대공약수 G, 최소공배수 L이라 하면
// A * B = L * G => L = A * B / G 를 활용

#include <iostream>
using namespace std;

#define endl "\n"

int gcd(int _a, int _b)
{
    while (_b != 0)
    {
        int r = _a % _b;
        _a = _b;
        _b = r;
    }
    return _a;
}

int lcm(int _a, int _b)
{
    return _a * _b / gcd(_a, _b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;
    while (t)
    {
        cin >> a >> b;

        cout << lcm(a, b) << endl;
        t--;
    }
    return 0;
}