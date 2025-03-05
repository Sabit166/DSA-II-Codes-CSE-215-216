#include <bits/stdc++.h>

using namespace std;
set<string> ans;

int lcs(string X, string Y, int m, int n, string s) {
    if (m == 0 || n == 0)
    {
        ans.insert(s);
        return 0;
    }
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1, s + X[m - 1]);
    else
        return max(lcs(X, Y, m, n - 1, s), lcs(X, Y, m - 1, n, s));
}

int main() {
    string X = "ABCBDAB", Y = "BDCAB";

    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS is " << lcs(X, Y, m, n, "") << endl;

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}