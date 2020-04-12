// https://www.acmicpc.net/problem/11401
// Divide_and_conquer(5), 이항 계수 3
// NUMBER 11401

#include <iostream>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    facMod[0] = 1;
    facMod[1] = 1;
    facMod[2] = 2;
    for (int i = 3; i <= n; i++)
        facMod[i] = (i * facMod[i - 1]) % MOD;
    long long second = (facMod[k] * facMod[n - k]) % MOD;
    cout << (facMod[n] % MOD) * (power(second, MOD - 2) % MOD) % MOD << endl;
    return 0;
}