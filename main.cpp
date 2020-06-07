// https://www.acmicpc.net/problem/5525
// NUMBER 5525, IOIOI

#include <iostream>
#define endl "\n"
#define INF 987654321
#define MAX_V 801
#define MAX_E 200001
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt = 0;
    string input;
    cin >> n >> m >> input;

    // 시간 복잡도는 O(N)
    for (int i = 0; i < m; i++) {
        // 'O' 의 갯수를 통해 문자열의 일치여부를 확인한다.
        int oCnt = 0;
        while (input[i] == 'I' && input[i + 1] == 'O') {  // (1) 번, 두 자리씩 코드를 확인한다.
            i += 2;
            oCnt++;
            if (input[i] == 'I' && oCnt == n) {
                // (2) 번, 이 논리의 핵심
                // oCnt의 갯수를 빼는 이유는 break문이 없는 것을 보면 알 수 있다.
                // 반복문을 지속하며 계속 문자열 단위별로 갯수를 세아린다.
                oCnt--;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}