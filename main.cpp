// https://www.acmicpc.net/problem/10816
// Binaray Search(2), 숫자 카드 2
// NUMBER 10816

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, mtemp;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input.begin(), input.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> mtemp;
        auto low = lower_bound(input.begin(), input.end(), mtemp);
        auto high = lower_bound(input.begin(), input.end(), mtemp + 1);
        cout << high - low << " ";
    }
    return 0;
}