class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int maxval = nums[0];
        int allmax = nums[0];
        int res = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < maxval)
            {
                res = i + 1;
                maxval = allmax;
            }
            else
            {
                allmax = max(allmax, nums[i]);
            }
        }

        return res;
    }
};