// https://www.acmicpc.net/problem/11050
// Math3 (7) 이항 계수
// NUMBER 11050

//

#include <iostream>
using namespace std;

#define endl "\n"

int Solve(int n, int k)
{
    int arr[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
        arr[i][0] = 1;
    for (int i = 0; i <= k; i++)
        arr[i][i] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int o = 1; o <= k; o++)
        {
            arr[i][o] = arr[i - 1][o] + arr[i - 1][o - 1];
        }
    }

    return arr[n][k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << Solve(n, k) % 10007 << endl;

    return 0;
}