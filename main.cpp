// https://www.acmicpc.net/problem/11723
// NUMBER 11723

#include <cstring>
#include <iostream>
#define endl "\n"
using namespace std;
int arr[2001], memo[2001][2001];

int pali(int from, int to) {
    if (from >= to) return 1;

    int &result = memo[from][to];
    if (result != -1) return result;

    if (arr[from] != arr[to]) return result = 0;

    return result = pali(from + 1, to - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    memset(memo, -1, sizeof(memo));
    cin >> m;
    for (int i = 0; i < m; i++) {
        int f, t;
        scanf("%d %d", &f, &t);
        printf("%d\n", pali(f, t));
    }
    return 0;
}