#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  string inp;
  cin >> n >> inp;

  int idx = 0;
  for (int i = 0; i < sz(inp); i++) {
    if (inp[i] == 'J' || inp[i] == 'A' || inp[i] == 'V') {
      continue;
    }

    inp[idx] = inp[i];
    idx++;
  }

  if (idx == 0) {
    cout << "nojava";
    return 0;
  }

  for (int i = idx; i < sz(inp); i++) {
    inp[i] = ' ';
  }

  cout << inp;
  return 0;
}
