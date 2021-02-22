#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, start;
    cin >> v >> e >> start;
    vector<vector<pair<int, int>>> edges(v + 1, vector<pair<int, int>>());
    vector<int> dist(v + 1, INT_MAX);
    dist[start] = 0;
    rep(i, e) {
        int from, to, w;
        cin >> from >> to >> w;
        edges[from].push_back({to, w});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur = pq.top().S;
        pq.pop();

        for (auto edge : edges[cur]) {
            int curVal = dist[edge.F];
            int newVal = dist[cur] + edge.S;

            if (newVal < curVal) {
                dist[edge.F] = newVal;
                pq.push({-1 * newVal, edge.F});
            }
        }
    }

    rep1(i, v) {
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
    return 0;
}
