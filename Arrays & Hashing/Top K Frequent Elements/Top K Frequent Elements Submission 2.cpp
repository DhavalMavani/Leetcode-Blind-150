class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq1;

        for (auto i : ump)
        {
            pq1.emplace(make_pair(i.second, i.first));
        }

        vector<int> v1;
        while (k > 0)
        {
            v1.emplace_back((pq1.top()).second);
            k--;
            pq1.pop();
        }
        return v1;
    }
};