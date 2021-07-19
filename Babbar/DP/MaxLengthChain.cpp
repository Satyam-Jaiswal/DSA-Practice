// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int cmp(struct val a, struct val b)
{
    return (a.first < b.first);
}
int maxChainLen(struct val p[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int dp[n + 1] = {0};
    int m = 0;
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (p[i].first > p[j].second)
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        m = max(dp[i], m);
    }
    return m;
}