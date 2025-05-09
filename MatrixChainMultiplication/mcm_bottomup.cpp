// C++ code to implement the 
// matrix chain multiplication using tabulation
#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr) {
  
    int n = arr.size();

    // Create a 2D DP array to store the minimum
    // multiplication costs
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP array.
    // Here, len is the chain length
    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // Print the DP table
    cout << "DP Table:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0)
                cout << setw(5) << "-";
            else
                cout << setw(5) << dp[i][j];
        }
        cout << endl;
    }

    // The minimum cost is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
  
    vector<int> arr = {30, 35, 15, 5, 10, 20, 25};
    // The dimensions of the matrices are given by the array
    cout << matrixMultiplication(arr);
    return 0;
}
