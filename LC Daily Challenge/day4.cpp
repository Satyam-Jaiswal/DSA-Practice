class Solution
{
public:
    int countVowelPermutation(int n)
    {
        long long int mod = 1000000007;

        //initilization
        //dp[i][j] be the number of strings of length i that ends with the j-th vowel.
        long long int dp[n + 1][5];
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
            dp[i][2] = 1;
            dp[i][3] = 1;
            dp[i][4] = 1;
        }

        //Creating combinations of each vowel using following conditions.
        //For a: ea, ia, ua
        //For e: ae, ie
        //For i: ei, oi
        //For o: io
        //For u: iu, ou

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] += (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] += (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] += (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] += (dp[i - 1][2]) % mod;
            dp[i][4] += (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }

        //Finding N-th and (N-1)-th solutions
        long long int x = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]) % mod;
        long long int y = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3] + dp[n - 1][4]) % mod;

        if (n == 1)
            return x;

        //Using basics of Modular Arithmetic to overcome overflow
        return (x % mod - y % mod + mod) % mod;
    }
};