#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(const string &X, const string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS is " << lcs(X, Y) << endl;

    return 0;
}