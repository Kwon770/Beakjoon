#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> cards;

int StarSolve(char nChar, string card, int from, int to)
{
    int cnt = 0;
    for (int i = from; i < to; i++)
    {
        if (nChar == card[i])
            return cnt;
        cnt++;
    }
    return -1;
}

void Solve(string input, string card)
{
    for (int i = 0; i < input.length(); i++)
    {
        for (int o = 0; o <)
            if (input[i] == '*')
            {
                if (isspace(input[i + 1]))
                    continue;
                else
                {
                    int temp = StarSolve(input[i + 1], card, i, input.length());
                    if (temp >= 0)
                    {
                        i += temp;
                        continue;
                    }
                    else
                        return;
                }
            }
            else if (input[i] == '?')
            {
                continue;
            }
            else
            {
                if (input[i] != card[i])
                    return;
            }
    }
    cards.push_back(card);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input, card;
    int T, Y;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cards.clear();
        cin >> input >> Y;
        for (int o = 0; o < Y; o++)
        {
            cin >> card;
            Solve(input, card);
        }

        sort(cards.begin(), cards.end());
        for (int i = 0; i < Y; i++)
            cout << cards[i] << endl;
    }

    return 0;
}