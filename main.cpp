// https://www.acmicpc.net/problem/18870
// NUMBER 18870, 좌표 압축

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> ipt(n);
    vector<int> iptS(n);
    for (int i = 0; i < n; i++) {
        cin >> ipt[i];
        iptS[i] = ipt[i];
    }
    sort(iptS.begin(), iptS.end());
    iptS.erase(unique(iptS.begin(), iptS.end()), iptS.end());
    for (int i = 0; i < n; i++) {
        cout << lower_bound(iptS.begin(), iptS.end(), ipt[i]) - iptS.begin() << " ";
    }
    cout << endl;
    return 0;
}