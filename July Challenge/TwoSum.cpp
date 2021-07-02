

// TC(O(n)) && sc(O(n))
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash; //num , index
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            int temptarget = target - nums[i];

            if (hash.find(temptarget) != hash.end()) // check if the value to be added exists in the hash
            {
                res.push_back(hash[temptarget]); //fetches index from already stored value
                res.push_back(i);                //Index of Current number
                return res;
            }
            hash[nums[i]] = i;
        }

        return res;
    }
};