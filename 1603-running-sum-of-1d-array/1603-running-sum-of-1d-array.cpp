class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int prefix=0;

        for(auto &i: nums){
            prefix+=i;
            ans.emplace_back(prefix);
        } 
        return ans;
    }
};