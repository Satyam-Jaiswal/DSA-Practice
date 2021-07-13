// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution
{
public:
    // int dp[1001][801];
    // Solution(){
    //     memset(dp, -1 ,sizeof(dp));
    // }
    int nCr(int n, int r)
    {
        // code here

        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                if (j == 0 || i == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
            }
        }

        return dp[n][r];
        // if(r==0 || n==r)
        // return dp[n][r]= 1;

        // if(dp[n][r]!=-1)
        // return dp[n][r];

        // return dp[n][r] = (nCr(n-1,r-1)+nCr(n-1,r))%mod;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends