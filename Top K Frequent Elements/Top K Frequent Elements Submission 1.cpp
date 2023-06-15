class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second >= b.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> v1;
        vector<pair<int, int>> v2 = {};
        unordered_map<int, int> ump;
        int mostFrequent = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
            mostFrequent = max(mostFrequent, ump[nums[i]]);
        }

        copy(ump.begin(), ump.end(), back_inserter(v2));
        sort(v2.begin(), v2.end(), comp);
        for (auto i : v2)
        {
            cout << i.first << " " << i.second << "\n";
        }
        cout << "\n";
        for (int i = 0; i < k; i++)
        {
            v1.emplace_back((*(v2.begin() + i)).first);
        }

        return v1;
    }
};