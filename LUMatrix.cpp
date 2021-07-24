// Source Code Link :
// https://github.com/Kwon770/Algorithm/blob/master/LUMatrix.cpp
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector<vector<double>> I;

vector<vector<double>> multiplyMatrix(const vector<vector<double>> &a,
                                      const vector<vector<double>> &b) {
  int ar = a.size(), ac = a.front().size(), bc = b.front().size();
  vector<vector<double>> ans(ar, vector<double>(bc));

  for (int i = 0; i < ar; i++) {
    for (int j = 0; j < bc; j++) {

      double result = 0;
      for (int k = 0; k < ac; k++) {
        result += a[i][k] * b[k][j];
      }
      ans[i][j] = result;
    }
  }

  return ans;
}

int getNonZeroRow(const vector<vector<double>> &a, int r, int c) {
  for (int bottomR = r; bottomR < (int)a.size(); bottomR++) {
    if (a[bottomR][c] != 0)
      return bottomR;
  }
  return -1;
}

vector<vector<double>> getEMatrix(const vector<vector<double>> &a, int r,
                                  int c) {
  vector<vector<double>> E = I;
  double eliminationVal = a[r][c] / a[c][c] * -1;
  E[r][c] = eliminationVal;
  return E;
}

void eliminateLowerTriangle(vector<vector<double>> &E,
                            vector<vector<double>> &matrix, int len) {
  for (int i = 0; i < len; i++) {
    // Row Exchange
    if (matrix[i][i] == 0) {
      int nonZeroIdx = getNonZeroRow(matrix, i + 1, i);
      swap(matrix[i], matrix[nonZeroIdx]);
    }

    // Eliminate bottom of pivot
    for (int j = i + 1; j < len; j++) {
      if (matrix[j][i] == 0)
        continue;

      auto tmpE = getEMatrix(matrix, j, i);
      matrix = multiplyMatrix(tmpE, matrix);
      E = multiplyMatrix(E, tmpE);
      matrix[j][i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int len;
  cout << "Input size of matrix : ";
  cin >> len;
  vector<vector<double>> A(len, vector<double>(len));

  cout << endl;
  cout << "Input matrix with blanks and line break" << endl;
  cout << "like this" << endl;
  cout << "1 2 3" << endl;
  cout << "1 2 3" << endl;
  cout << "1 2 3" << endl;
  cout << ">> " << endl;
  cout << endl;

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      cin >> A[i][j];
    }
  }

  // Make unit matrix
  I.resize(len, vector<double>(len, 0));
  for (int i = 0; i < len; i++)
    I[i][i] = 1;

  vector<vector<double>> E = I;
  vector<vector<double>> U = A;
  eliminateLowerTriangle(E, U, len);

  vector<vector<double>> L = I;
  eliminateLowerTriangle(L, E, len);

  cout << endl;
  cout << endl;
  cout << "L : " << endl;
  for (auto a : L) {
    cout << "[ ";
    for (auto b : a) {
      cout << setw(10) << b << " ";
    }
    cout << " ] " << endl;
  }

  cout << endl;
  cout << "U : " << endl;
  for (auto a : U) {
    cout << "[ ";
    for (auto b : a) {
      cout << setw(10) << b << " ";
    }
    cout << " ] " << endl;
  }

  return 0;
}
