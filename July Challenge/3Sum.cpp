
// Code is kind of self explainotry

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n == 0)
        {
            return res; // a corner case of the problem
        }
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i];
                while (lo < hi)
                {
                    if (nums[lo] + nums[hi] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        //two sum logic
                        while (lo < hi && nums[lo] == nums[lo + 1])
                            lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1])
                            hi--;

                        lo++;
                        hi--;
                    }
                    else if (nums[lo] + nums[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return res;
    }
};