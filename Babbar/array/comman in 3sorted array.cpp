// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int check(int a, int b, int c)
    {
        int temp = min({a, b, c});

        if (temp == a)
            return 1;
        else if (temp == b)
            return 2;
        else
            return 3;
    }
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        vector<int> arr1;

        int p1 = 0, p2 = 0, p3 = 0;

        int rec = INT_MIN;

        while (p1 < n1 && p2 < n2 && p3 < n3)
        {
            if (A[p1] == B[p2] && B[p2] == C[p3])
            {
                if (rec != A[p1])
                {
                    rec = A[p1];
                    arr1.push_back(A[p1]);
                }
                ++p1;
            }
            else
            {
                int choice = check(A[p1], B[p2], C[p3]);

                if (choice == 1)
                    ++p1;
                else if (choice == 2)
                    ++p2;
                else
                    ++p3;
            }
        }

        if (arr1.size() == 0)
            arr1.push_back(-1);

        return arr1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends