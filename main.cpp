// https://www.acmicpc.net/problem/9370
// Shortest path 3, 미확인 도착지
// NUMBER 9370

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 987654321
#define MAX_E 50001
#define MAX_N 2001
using namespace std;

struct NODE {
    int to;
    int val;
};

vector<int> dijkstra(int startNode, int nodeCount, vector<NODE> edges[MAX_N]) {
    vector<int> distances(nodeCount + 1);
    for (int i = 1; i <= nodeCount; i++) {
        distances[i] = INF;
    }
    distances[startNode] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        pq.pop();

        int size = edges[cur_node].size();
        for (int i = 0; i < size; i++) {
            int new_val = distances[cur_node] + edges[cur_node][i].val;
            int before_val = distances[edges[cur_node][i].to];

            if (new_val < before_val) {
                distances[edges[cur_node][i].to] = new_val;
                pq.push({-1 * new_val, edges[cur_node][i].to});
            }
        }
    }
    return distances;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Testcase;
    cin >> Testcase;
    for (int i = 0; i < Testcase; i++) {
        vector<NODE> edges[MAX_N];
        vector<int> destinations;
        vector<int> ans;

        // 입력
        int nodeCount, edgeCount, destinationCount;
        cin >> nodeCount >> edgeCount >> destinationCount;
        int start, cur1, cur2, curEdgeDistance;
        cin >> start >> cur1 >> cur2;

        for (int j = 0; j < edgeCount; j++) {
            int from, to, distance;
            cin >> from >> to >> distance;
            edges[from].push_back({to, distance});
            edges[to].push_back({from, distance});

            if ((cur1 == from || cur1 == to) && (cur2 == from || cur2 == to)) {
                curEdgeDistance = distance;
            }
        }

        for (int j = 0; j < destinationCount; j++) {
            int destination;
            cin >> destination;
            destinations.push_back(destination);
        }

        // 해결
        vector<int> fromStart = dijkstra(start, nodeCount, edges);
        int cur, distanceToCur = 0;
        if (fromStart[cur1] < fromStart[cur2]) {
            cur = cur2;
            distanceToCur += fromStart[cur1];
        } else {
            cur = cur1;
            distanceToCur += fromStart[cur2];
        }
        distanceToCur += curEdgeDistance;

        vector<int> fromCur = dijkstra(cur, nodeCount, edges);

        for (int j = 0; j < destinationCount; j++) {
            int distanceWithCur = distanceToCur + fromCur[destinations[j]];
            int distanceWithoutCur = fromStart[destinations[j]];

            if (distanceWithCur <= distanceWithoutCur) ans.push_back(destinations[j]);
        }

        sort(ans.begin(), ans.end());
        for (auto iter = ans.begin(); iter != ans.end(); iter++) cout << *iter << " ";
        cout << endl;
    }

    return 0;
}