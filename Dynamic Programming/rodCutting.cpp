//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int DP[1010];
    int maxPiece(int piece,int price[],int sz)
    {
        if(piece==0) return 0;
        if(DP[piece]!=-1) return DP[piece];
        
        int mx=0;
        for(int i=0;i<sz;i++)
        {
            if(piece-i-1>=0)  mx=max(mx,price[i]+maxPiece(piece-i-1,price,sz));
        }
        return DP[piece]=mx;
    }
    
  public:
    int cutRod(int price[], int n) {
        memset(DP,-1,sizeof(DP));
        return maxPiece(n,price,n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends