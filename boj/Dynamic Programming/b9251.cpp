// https://www.acmicpc.net/problem/9251
// Dynamic Programming (14), LCS
// NUMBER 9251

// Study Note, https://www.notion.so/sckwon770/9251-LCS-c39aefd27cc343cda29f94a4b1c90799

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1001][1001], i, o;
    string s1, s2;
    cin >> s1 >> s2;
    for (i = 1; i <= s1.length(); i++)
    {
        for (o = 1; o <= s2.length(); o++)
        {
            if (s1[i - 1] == s2[o - 1])
                dp[i][o] = dp[i - 1][o - 1] + 1;
            else
                dp[i][o] = max(dp[i - 1][o], dp[i][o - 1]);
        }
    }
    cout << dp[i - 1][o - 1] << endl;

    return 0;
}