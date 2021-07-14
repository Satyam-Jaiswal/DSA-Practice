// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int dp[101][101];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    int editDistance(string s, string t)
    {
        // Code here

        int m = s.length();
        int n = t.length();
        return solve(s, t, m, n);
    }

    int solve(string s, string t, int m, int n)
    {
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == t[n - 1])
            return dp[m][n] = solve(s, t, m - 1, n - 1);
        else
        {
            return dp[m][n] = 1 + min(solve(s, t, m - 1, n), min(solve(s, t, m - 1, n - 1), solve(s, t, m, n - 1)));
        }
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends