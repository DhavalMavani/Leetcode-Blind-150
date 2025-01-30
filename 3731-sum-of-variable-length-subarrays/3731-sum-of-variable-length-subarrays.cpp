class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        int currSum=0, ans=0;
        for(int i=0;i<n;i++){
            prefix[i]=currSum;
            currSum+=nums[i];
            int str=max(0,i-nums[i]);
            ans+=currSum-prefix[str];
        }
        return ans;
    }
};