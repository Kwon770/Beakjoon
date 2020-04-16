#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
vector<int> histogram;
int leftH, leftW, rightH, rightW;

void leftCheck(int idx)
{
    int tempH = leftH;
    for (int i = idx - 1; i > 0; i--)
    {
        int newWidth = (idx - i) + 1;
        if (tempH > histogram[i])
        {
            if (leftW * leftH < newWidth * histogram[i])
            {
                leftW = newWidth;
                leftH = histogram[i];
            }
            tempH = histogram[i];
        }
        else
        {
            if (leftW * leftH < newWidth * tempH)
            {
                leftW = newWidth;
                leftH = tempH;
            }
        }
    }
}

void rightCheck(int idx)
{
    int tempH = rightH;
    for (int i = idx + 1; i < static_cast<int>(histogram.size()); i++)
    {
        int newWidth = (i - idx) + 1;
        if (tempH > histogram[i])
        {
            if (rightW * rightH < newWidth * histogram[i])
            {
                rightW = newWidth;
                rightH = histogram[i];
            }
            tempH = histogram[i];
        }
        else
        {
            if (rightW * rightH < newWidth * tempH)
            {
                rightW = newWidth;
                rightH = tempH;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp;
    while (true)
    {
        cin >> n;
        if (!n)
            break;
        histogram.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            histogram.push_back(temp);
        }

        int idx = max_element(histogram.begin(), histogram.end()) - histogram.begin();
        leftW = rightW = 1;
        leftH = rightH = histogram[idx];
        rightCheck(idx);
        leftCheck(idx);
        cout << max(max(leftW * leftH, rightW * rightH), min(leftH, rightH) * (leftW + rightW - 1)) << endl;
    }
    return 0;
}