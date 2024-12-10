#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int coin[3] = {3, 1, 4};

int main()
{
    //for(int i=0;i<=3;i++) dp[i][0]=1;
    dp[1][0]=1;
    for (int j = 1; j <= 3; j++)
    {
        for (int i = 1; i <= 8; i++)
        {
            if (dp[j - 1][i] || (i >= coin[j-1] && dp[j - 1][i - coin[j-1]]))
            {
                dp[j][i] = 1;
            }
        }
    }
    for (int a = 0; a <= 3; a++)
    {
        for (int b = 0; b <= 7; b++)
            cout << dp[a][b] << ' ';
        cout << endl;
    }
    cout << "\n\n";
    cout << dp[3][7];
}