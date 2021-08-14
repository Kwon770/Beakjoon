// https://www.acmicpc.net/problem/2641
// 2641 다각형 그리기
// Memory : 2156 KB , Time : 0 ms
//
// 문제의 의도를 파악해야 풀 수 있는 문제다.
// 굳이 다각형의 모양을 숫자로 주었으므로, 이 숫자들을 이용하여 다른 방향의 도형도 파악해야한다.
// 패턴이 주어지는 문제의 경우, 그 패턴 자체로 풀 수 있는 문제가 많다고 함.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define pq priority_queue

int len, n, idx;
list<int> standard, reverseStandard;
list<int> comparison;
bool isSame;

bool compare(list<int>& standard, list<int> comparison) {
    for (int j = 0; j < len; j++) {

        isSame = true;
        int rotation = standard.front() - comparison.front();
        for (auto standardIter = standard.begin(), comparisonIter = comparison.begin();
        standardIter != standard.end(); standardIter++, comparisonIter++) {
            if (*standardIter != *comparisonIter + rotation) {
                isSame = false;
                break;
            }
        }

        if (isSame) {
            return true;
        }

        comparison.push_back(comparison.front());
        comparison.pop_front();
    }

    return false;
}

int reverseNumber(int n) {
    if (n > 2) {
        return n - 2;
    } else {
        return n + 2;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> len;
    for (int j = 0; j < len; j++) {
        cin >> n;
        standard.push_back(n);
        reverseStandard.push_front(reverseNumber(n));
    }
    cin >> idx;

    int ans = 0;
    vector<list<int>> anss;
    for (int i = 0; i < idx; i++) {
        comparison.clear();
        for (int j = 0; j < len; j++) {
            cin >> n;
            comparison.push_back(n);
        }

        if (compare(standard, comparison) || compare(reverseStandard, comparison)) {
            ans++;
            anss.push_back(comparison);
        }
    }

    cout << ans << endl;
    for (auto com : anss) {
        for (auto c : com) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}