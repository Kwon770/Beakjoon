// https://www.acmicpc.net/problem/11055
// 11055 가장 큰 증가 부분 수열
// Memory : 2020 KB , Time : 0 ms
//
// ..

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int solution(vector<vector<int>> sizes) {
    int maxVal = INT_MIN, minVal = INT_MIN;

    for (auto wallet : sizes) {
        int big = max(wallet[0], wallet[1]);
        int small = min(wallet[0], wallet[1]);

        maxVal = max(maxVal, big);
        minVal = max(minVal, small);
    }

    return maxVal * minVal;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<vector<int>> a = {{1,2}, {3,4}};
  cout << solution(a);
  return 0;
}