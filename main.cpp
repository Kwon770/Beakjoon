// https://www.acmicpc.net/problem/1912
// Dynamic Programming (15), 연속합
// NUMBER 1912

#include <iostream>

using namespace std;
#define MAX 100000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[MAX], dp[MAX], maxVal = -1001;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    maxVal = max(maxVal, dp[0]);
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxVal = max(maxVal, dp[i]);
    }

    cout << maxVal << endl;

    return 0;
}