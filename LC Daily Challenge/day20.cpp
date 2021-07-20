class Solution
{
public:
    Solution(vector<int> &nums)
    {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> shuffled = original;

        for (int i = original.size() - 1; i >= 0; i--)
        {
            int r = rand() % (i + 1);
            swap(shuffled[i], shuffled[r]);
        }

        return shuffled;
    }

private:
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */