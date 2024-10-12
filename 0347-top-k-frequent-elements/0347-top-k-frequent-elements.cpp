class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map <int,int> ump;

        for (int i=0; i<n; i++) ump[nums[i]]++;

        priority_queue < pair<int,int> > pq;

        for (auto &i: ump) pq.push({i.second,i.first});

        vector <int> ans;
        while(k--){
            ans.emplace_back( (pq.top()).second );
            pq.pop();
        }

        return ans;
    }
};