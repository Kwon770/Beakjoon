#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  For(i, 0, t) {
    string str;
    cin >> str;

    int failIdx = ln(str) - 1;
    int last = str[ln(str) - 1];
    bool changed = false;
    for (auto iter = str.rbegin() + 1; iter != str.rend(); iter++) {
      if (last == '0') {
        if (*iter == '1') {
          int tmp = iter - str.rbegin();
          failIdx = ln(str) - tmp - 1;
          break;
        }
      } else {
        if (changed) {
          if (*iter == '1') {
            int tmp = iter - str.rbegin();
            failIdx = ln(str) - tmp - 1;
            break;
          }
        } else {
          if (*iter == '0')
            changed = true;
        }
      }

      return 0;
    }
