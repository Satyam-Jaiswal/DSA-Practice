class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[n - 1];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            int lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum > target)
                {
                    hi--;
                }
                else
                    lo++;

                // this is the main logic whict differenciate it from 3 sum
                if (abs(sum - target) < abs(res - target))
                {
                    res = sum;
                }
            }
        }

        return res;
    }
};