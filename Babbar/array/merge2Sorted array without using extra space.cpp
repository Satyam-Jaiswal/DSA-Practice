// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    void sort(int a[], int n)
    {
        int i = 0;
        while (i < n - 1 && a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            i++;
        }
    };
    void merge(int a[], int b[], int n, int m)
    {

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] > b[j])
            {
                swap(a[i], b[j]);
                sort(b, m);
                i++;
            }
            else
                i++;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends