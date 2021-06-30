class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        int length = intervals.size();

        if (length == 0)
            return result;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
             { return a[0] < b[0]; });

        result.push_back(intervals[0]);

        for (int i = 1; i < length; ++i)
        {
            vector<int> backVec = result.back();

            if (intervals[i][0] > backVec[1])
            {
                result.push_back(intervals[i]);
            }
            else
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }
};