class Solution
{
public:
    string pushDominoes(string a)
    {
        int n = a.size(), h, j, f = -1;
        char l = 'L', r;
        for (int i = 0; i <= n; i++)
        {
            if (i < n)
                r = a[i];
            else
                r = 'R';
            if (r != '.')
            {
                if (l == 'L' && r == 'L')
                    for (int j = f + 1; j < i; j++)
                        a[j] = 'L';
                else if (l == 'R' && r == 'R')
                    for (int j = f + 1; j < i; j++)
                        a[j] = 'R';
                else if (l == 'R' && r == 'L')
                {
                    h = i - f - 1;
                    j = i;
                    while (!(h == 0 || h == 1))
                    {
                        a[++f] = 'R';
                        a[--j] = 'L';
                        h -= 2;
                    }
                    l = 'L';
                }
                else
                    l = 'R';
                f = i;
            }
        }
        return a;
    }
};

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool check(vector<int> A, int N)
{
    int x;
    bool p = 0;
    for (x = 0; x < N - 2; x++)
    {
        if ((A[x] < A[x + 1] && A[x + 1] > A[x + 2]) || (A[x] > A[x + 1] && A[x + 1] < A[x + 2]))
        {
            p = 1;
        }
        else
        {
            break;
        }
    }
    if (p == 1 && x == N - 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int solution(vector<int> &A)
{
    int count = 0;
    int N = A.size();
    vector<int> ArrayCopy(N);

    if ((check(A, N)) == 0)
    {
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int m = 0; m < N; m++)
        {
            ArrayCopy[m] = A[m];
        }

        for (int m = i; m < N - 1; m++)
        {
            ArrayCopy[m] = ArrayCopy[m + 1];
        }

        if (check(ArrayCopy, N - 1) == 0)
        {
            count++;
        }
    }

    if (count == 0)
    {
        count = -1;
    }

    return count;
}

#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> blocks)
{
    int n = blocks.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    right[n - 1] = 0;
    left[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (blocks[i] <= blocks[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (blocks[i] <= blocks[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, right[i] + left[i] + 1);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> blocks(n, 0);
    for (int i = 0; i < n; i++)
        cin >> blocks[i];
    cout << solution(blocks);
}