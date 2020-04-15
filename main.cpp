// https://www.acmicpc.net/problem/2749
// Divide_and_conquer(8), 피보나치 수3
// NUMBER 2749

#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define MOD 1000000
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p = 1500000, fibo[1500000];
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;
    long long n;
    cin >> n;
    n %= p;
    for (int i = 3; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }
    cout << fibo[n] << endl;
    return 0;
}