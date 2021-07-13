// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n)
    {
        // code here
        ll maxP, minP, res;

        maxP = minP = res = 1;

        for (int i = 0; i < N; i++)
        {
            ll x = A[i];

            if (x < 0)
                swap(maxP, minP);

            maxP = max(x, x * maxP);
            minP = min(x, x * minP);

            res = max(res, maxP);
        }

        return res;
    }

    // 	6 -3 -10 0 2

    // 	max=-3, min=-18, res=6;

    // 	x=-10;
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends