class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map <int,int> ump;
        for(int i=0;i<n;i++){
            if(!ump.count(target-nums[i]) ) ump[nums[i]]=i;
            else return {i, ump[ target-nums[i] ] };
        }
        return {};
    }
};