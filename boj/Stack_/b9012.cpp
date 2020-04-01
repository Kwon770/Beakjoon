// https://www.acmicpc.net/problem/9012
// Stack(3), 괄호
// NUMBER 9012

// 괄호가 정상적일려면 '(' 과 ')' 이 짝이 맞아야 되므로, ')' 이 나온 앞에 무조건 '(' 이 나와야만 한다는 것을 이용
// 순서대로 확인하므로 vector 을 이용

// 벡터를 확인할때 올바르지 못한 식일 경우, 백터를 확인할때 런타임 오류가 뜰 수 있으므로, vec.size() 를 확인한다,

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> vec;
    string input;
    bool isVsc = true;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vec.clear();
        isVsc = true;

        cin >> input;
        for (int o = 0; o < input.length(); o++)
        {
            if (input[o] == '(')
                vec.push_back(input[o]);
            else
            {
                if (vec.size() == 0)
                {
                    isVsc = false;
                    break;
                }

                if (vec[vec.size() - 1] == '(')
                    vec.pop_back();
                else
                {
                    isVsc = false;
                    break;
                }
            }
        }

        if (!isVsc || vec.size() != 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}