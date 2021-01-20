#include <cstring>
#include <climits>
#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> coin;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		coin.insert(inp);
	}

	int cache[101][10001];
	memset(cache, 0, sizeof(cache));
	int idx = 1;
	for (auto iter = coin.begin(); iter != coin.end(); iter++, idx++) {
		for (int j = 0; j <= k; j++) {
			if (idx <= 1) {
				if (j % *iter == 0) cache[idx][j] = j / *iter;
				else cache[idx][j] = INT_MAX;

				continue;
			}

			if (j - *iter >= 0) {
				cache[idx][j] = min(cache[idx - 1][j], cache[idx][j - *iter] + 1);
			} else {
				cache[idx][j] = cache[idx - 1][j];
			}
		}
	}

	int w = 1;
	for (auto iter = coin.begin(); iter != coin.end(); iter++, w++) {
		for (int j = 0; j <= k; j++) {
			cout << cache[w][j] << " ";
		}
		cout << endl;
	}
	int last = idx - 1;
	cout << (cache[last][k] == INT_MAX ? -1 : cache[last][k]);
	return 0;
}
