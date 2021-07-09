class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t(n, 0);
        t[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i] && t[i] < t[j])
                {
                    t[i] = t[j];
                }
            }
            t[i]++;
            ans = max(ans, t[i]);
        }

        return ans;
    }
};