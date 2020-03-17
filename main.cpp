// https://www.acmicpc.net/problem/2565
// Dynamic Programming (13), 전깃줄
// NUMBER 2565

// 이 문제는 2개의 핵심점을 파악해야 dp로 풀 수 있는데,
// 1. 합선이 되는 경우는, 선(a, b) 선(q,w) 이 있을때
//    (1) a < q && b > w
//    (2) a > q && b < w
// 2. 결국 합선아 되지 않기 위해서는 A 전봇대를 기준으로 했을때 B 전봇대를 향하는 전선이 내림차순 혹은 오름차순이여야 함
// 따라서 B를 향한 전선이 오름차순인 경우를 찾고,
// 최소로 선을 제거한 갯수를 구해야 하므로 가장 긴 증가하는 부분 수열을 구하면 됨

#include <iostream>

using namespace std;
#define MAX 501
int wire[MAX], lis[MAX], n, maxLen = 0;

void Solve()
{
    int cnt = 0;
    for (int i = 1; i < MAX; i++)
    {
        if (!wire[i])
            continue;

        for (int o = 1; o < i; o++)
        {
            if (!wire[o])
                continue;

            if (wire[o] < wire[i])
            {
                lis[i] = max(lis[i], lis[o] + 1);
            }
            maxLen = max(maxLen, lis[i]);
        }

        cnt++;
        if (cnt == n)
            break;
    }
    cout << n - maxLen << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        wire[a] = b;
    }
    fill_n(lis, MAX, 1);
    Solve();

    return 0;
}