// https://www.acmicpc.net/problem/11726
// NUMBER 11726, 2 x N 타일링

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
#define MOD 10007

int factorial(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int one = n, two = 0, cnt = 0;
    for (int i = 0; i <= n / 2; i++) {
        cnt += (factorial(one + two) / (factorial(one) * factorial(two))) % MOD;
        one -= 2;
        two += 1;
    }
    cout << cnt % MOD << endl;
    return 0;
}