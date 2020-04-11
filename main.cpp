// https://www.acmicpc.net/problem/1629
// Divide_and_conquer(4), 곱셈
// NUMBER 1629

#include <iostream>
using namespace std;
#define endl '\n'

long long pow(int a, int b, int c)
{
    if (b == 1)
        return a;
    else
    {
        long long temp = pow(a, b / 2, c);
        if (b % 2)
            return ((temp * temp) % c * a) % c;
        else
            return (temp * temp) % c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a % c, b, c) << endl;
    return 0;
}