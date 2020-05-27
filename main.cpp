// https://www.acmicpc.net/problem/11726
// NUMBER 11726, 2 x N 타일링

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
#define MOD 10007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int square[1001], n;
    cin >> n;
    square[1] = 1;
    square[2] = 2;
    for (int i = 3; i <= n; i++) square[i] = (square[i - 2] + square[i - 1]) % MOD;
    cout << square[n] << endl;
    return 0;
}