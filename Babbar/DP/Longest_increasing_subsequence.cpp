// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {

        vector<int> t;
        t.push_back(arr[0]);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > t.back())
            {
                t.push_back(arr[i]);
            }
            else
            {
                int index = lower_bound(t.begin(), t.end(), arr[i]) - t.begin();
                t[index] = arr[i];
            }
        }

        ans = t.size();

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends