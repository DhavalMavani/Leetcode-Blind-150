class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        
        unordered_map <int,int> ump;
        for(auto &i: nums) ump[i]++;

        vector<int> ans;
        for(auto &i: ump) if(i.second>n) ans.emplace_back(i.first);

        return ans;
    }
};