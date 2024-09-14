class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,sum=0;
        unordered_map<int,int> prefixSum;
        prefixSum[0]=1;

        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            ans=ans+prefixSum[sum-goal];
            prefixSum[sum]++;
        }
        return ans;
    }
};