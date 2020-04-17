#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define endl "\n"
#define MAX 1000

void getHistogram(double *prX, int iN, double (*prHistogram)[3])
{
    sort(prX, prX + MAX);
    double range = (prX[MAX - 1] - prX[0] + 1) / iN;
    double init = prX[0];

    int prevIdx = 0, curIdx = 0;
    for (int i = 0; i < iN; i++)
    {
        double sum = 0, deviationPow = 0;
        int cnt = 0;

        // Check whether the numbuer belong to range
        while (prX[curIdx] <= init + (range * (i + 1) - 1))
        {
            sum += prX[curIdx];
            cnt++;
            curIdx++;
            // out of range
            if (curIdx >= MAX)
                break;
        }
        prHistogram[i][0] = cnt;
        prHistogram[i][1] = sum / cnt;
        for (int o = prevIdx; o < curIdx; o++)
        {
            deviationPow += pow(prX[o] - prHistogram[i][1], 2);
        }
        prevIdx = curIdx;
        prHistogram[i][2] = sqrt(deviationPow / prHistogram[i][0]);

        cout << prHistogram[i][0] << endl;
        cout << prHistogram[i][1] << endl;
        cout << prHistogram[i][2] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    double *prX = new double[MAX];
    double(*prHistogram)[3] = new double[n][3];
    for (int i = 0; i < MAX; i++)
    {
        prX[i] = rand() % MAX + 1;
        cout << prX[i] << endl;
    }

    getHistogram(prX, n, prHistogram);

    delete[] prX;
    delete[] prHistogram;
    return 0;
}