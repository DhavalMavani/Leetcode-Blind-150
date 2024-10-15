class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int,int> ump;

        for(auto &i: nums){
            ump[i]++;
            if(ump.size()==3){
                vector<int> remove;
                for(auto &it: ump){
                    it.second--;
                    if(it.second==0) remove.emplace_back(it.first);
                }
                for(auto &j: remove) ump.erase(j);
            }
        }
        for(auto &it: ump) it.second=0;

        for(auto &i: nums) if(ump.count(i)) ump[i]++;

        int n=nums.size()/3;
        for(auto &it: ump) if(it.second>n) ans.emplace_back(it.first);

        return ans;
    }
};