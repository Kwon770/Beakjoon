// https://www.acmicpc.net/problem/11726
// NUMBER 11726, 2 x N 타일링

// 블럭의 배치 방향에 따른 경우의 수
// 틀의 높이는 2로 고정이므로, 너비만 고려하여야하므로, 1블럭 2블럭 - 2가지 경우만 생각한다.
// 기존 크기의 틀에서 한 칸 늘어날 경우, 블럭이 그 한 칸에 추가될 수 있는 경우의 수는
// n 크기의 들일 경우) n - 1 크기의 틀에 1블럭
// n 크기의 들일 경우) n - 2 크기의 틀에 2블럭  => 2가지 뿐이다.
// 따라서 다음의 규칙을 이용해여 d[n] = d[n - 1] + d[n - 2] 의 점화식이 성립된다.

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