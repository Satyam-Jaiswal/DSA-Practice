#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]
        }
        int maxval = *max_element(a.begin(), a.end());
        int minval = *min_element(a.begin(), a.end());
        int num = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxval)
            {
                a[i] = minval;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            num += (a[i] / minval);
        }
        cout << num << endl;
    }
    return 0;
}