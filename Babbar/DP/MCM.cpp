// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
#define ll long long
    int dp[101][101];
    int solve(int arr[], ll i, ll j)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        ll temp;
        ll ans = INT_MAX;
        for (ll k = i; k <= j - 1; k++)
        {
            temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, temp);
            dp[i][j] = ans;
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, N - 1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends