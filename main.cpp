// https://www.acmicpc.net/problem/4949
// Stack(4), 균형잡힌 세상
// NUMBER 4949

#include <iostream>
#include <stack>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    bool isBlanace;
    while (true)
    {
        getline(cin, input);
        if (input == ".")
            break;

        stack<char> stack;
        isBlanace = true;
        for (int i = 0; i < input.length() && isBlanace; i++)
        {
            switch (input[i])
            {
            case '[':
            case '(':
                stack.push(input[i]);
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    isBlanace = false;
                break;
            case ')':
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    isBlanace = false;
                break;
            default:
                break;
            }
        }

        if (isBlanace && stack.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}