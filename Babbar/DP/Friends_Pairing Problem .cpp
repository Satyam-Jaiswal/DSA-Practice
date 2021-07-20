// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
#define mod 1000000007
    int countFriendsPairings(int n)
    {
        // code here
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (long long int i = 3; i <= n; i++)
        {
            dp[i] = ((dp[i - 1]) % mod + (i - 1) % mod * (dp[i - 2]) % mod) % mod;
        }
        return dp[n];
    }

    // 3===single======pair bna do
    // 0==0
    // 1====1(single)
    // 2=====2
    // 3===4
    // 4===  1+2+3=6   10
    // n=fn(n-1)+n-1*(fn(n-2))
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends