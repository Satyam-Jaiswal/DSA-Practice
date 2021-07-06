class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        vector<pair<int, int>> v;

        //map to keep a track of count of occuring each element
        unordered_map<int, int> m;
        int n = arr.size();
        for (auto i : arr)
            m[i]++;
        int total = 0; //sum of indexes

        //storing the frequency in a vector sotring them.
        for (auto i : m)
        {
            v.push_back({i.second, i.first});
            total += i.second;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int k = 0;
        while (total > n / 2)
        {
            total -= v[k].first; //once the total value becomes less than or equal to n/2
            k++;                 //we terminate the loop
        }                        //apporach is to elenemate the no with max occourence toh reduce the size of the
        return k;                //removed elements set.
    }
};