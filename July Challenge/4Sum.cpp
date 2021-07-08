class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = target - nums[i] - nums[j];
                int lo = j + 1;
                int hi = n - 1;
                while (hi > lo)
                {
                    int temp = nums[lo] + nums[hi];
                    if (temp < sum)
                    {
                        lo++;
                    }
                    else if (temp > sum)
                    {
                        hi--;
                    }
                    else
                    {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[lo]);
                        ans.push_back(nums[hi]);
                        res.push_back(ans);

                        while (lo < hi and nums[lo] == ans[2])
                            lo++;
                        while (lo < hi and nums[hi] == ans[3])
                            hi--;
                    }
                }
                while (j + 1 < n and nums[j + 1] == nums[j])
                {
                    j++;
                }
            }
            while (i + 1 < n and nums[i + 1] == nums[i])
            {
                i++;
            }
        }

        return res;
    }
};