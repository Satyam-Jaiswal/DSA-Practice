// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // n : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        vector<int> hash(100001, 0);
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]] = 1;
        }
        int i = 0;
        int max = 1;
        while (i < 100001)
        {
            int cnt = 0;
            while (i < 100001 && hash[i] != 0)
            {
                i++;
                cnt++;
            }
            if (cnt > max)
                max = cnt;
            while (i < 100001 && hash[i] == 0)
            {
                i++;
            }
        }
        return max;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends