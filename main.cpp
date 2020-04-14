// https://www.acmicpc.net/problem/2740
// Divide_and_conquer(6), 행렬 곱셈
// NUMBER 2740

// 행렬의 곱 https://www.notion.so/sckwon770/43c262912bf34e9ab4da3e11d5c64ec3

#include <iostream>
using namespace std;
#define endl "\n"
#define MOD 1000
int n, b, Temp[6][6] = {{0}};

void cal(int A[6][6], int B[6][6])
{
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++)
            for (int p = 1; p <= n; p++)
                Temp[i][o] += A[i][p] * B[p][o] % MOD;

    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++)
        {
            A[i][o] = Temp[i][o] % MOD;
            Temp[i][o] = 0;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Result[6][6], Origin[6][6];
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++)
        {
            cin >> Result[i][o];
            Origin[i][o] = Result[i][o];
        }

    while (b > 0)
    {
        if (b % 2)
        {
            cal(Result, Origin);
        }
        cal(Result, Result);
        b /= 2;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int o = 1; o <= n; o++)
            cout << Result[i][o] << " ";
        cout << endl;
    }
    return 0;
}