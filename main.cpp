// https://www.acmicpc.net/problem/11053
// Dynamic Programming (11), 가장 긴 증가하는 부분 수열
// NUMBER 11053

#include <iostream>

using namespace std;
#define MAX 1001
int input[MAX], maxLen = 0;

void Solve(int n)
{
    int result[n + 1];
    fill_n(result, n + 1, 1);
    for (int i = n; i > 0; i--)
    {
        for (int o = i; o <= n; o++)
        {
            if (input[i] < input[o])
                result[i] = max(result[i], result[o] + 1);
            maxLen = max(maxLen, result[i]);
        }
    }
    cout << maxLen << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    Solve(N);
    return 0;
}