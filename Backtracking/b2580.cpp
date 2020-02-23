// https://www.acmicpc.net/problem/2580
// Backtracking (6) 스도쿠
// NUMBER 2580

//

#include <iostream>
#include <vector>

#define endl "\n"

int arr[9][9];

int GetUnitValue(int idx)
{
    switch (idx)
    {
    case 0:
    case 1:
    case 2:
        return 0;
    case 3:
    case 4:
    case 5:
        return 3;
    case 6:
    case 7:
    case 8:
        return 6;
    }
    return 0;
}

int Solve(int x, int y)
{
    std::vector<int> vec;
    for (int i = 1; i <= 9; i++)
        vec.push_back(i);

    for (int i = 0; i < 9; i++)
    {
        vec.erase(std::remove(vec.begin(), vec.end(), arr[i][y]), vec.end());
        vec.erase(std::remove(vec.begin(), vec.end(), arr[x][i]), vec.end());
    }

    int xOff = GetUnitValue(x);
    int yOff = GetUnitValue(y);
    for (int i = xOff; i < xOff + 3; i++)
    {
        for (int o = yOff; o < yOff + 3; o++)
        {
            if (x == i && y == o)
                continue;

            vec.erase(std::remove(vec.begin(), vec.end(), arr[i][o]), vec.end());
        }
    }

    return vec[0];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            std::cin >> arr[i][o];
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            if (arr[i][o] == 0)
                arr[i][o] = Solve(i, o);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int o = 0; o < 9; o++)
        {
            std::cout << arr[i][o] << " ";
        }
        std::cout << endl;
    }

    return 0;
}