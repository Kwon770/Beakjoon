// https://www.acmicpc.net/problem/1300
// Binaray Search(6), K번째 수
// NUMBER 1300

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n, c, temp;
vector<int> houses;

bool isPossible(int dist) {
    int cnt = 1;
    int prev = houses[0];
    for (int i = 1; i < n; i++) {
        if (houses[i] - prev >= dist) {
            cnt++;
            prev = houses[i];
        }
    }

    if (cnt >= c)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        houses.push_back(temp);
    }
    sort(houses.begin(), houses.end());
    int low = 1,
        high = houses[n - 1] - houses[0],
        result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            result = max(result, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << result << endl;
    return 0;
}