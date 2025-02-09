#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[10001] = {0};

int minCost(int n)
{
    if(n == 0) return 0;
    if(dp[n]) return dp[n];
    int mn = INT_MAX;
    for(int i = 1; i <= 10 && n - i*i >= 0; i++)
    {
        mn = min(mn , 1 + minCost(n - i*i));
    }
    return dp[n] = mn;
}

signed main() {
    int n;
    cin >> n;
    cout << minCost(n) << endl;
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/