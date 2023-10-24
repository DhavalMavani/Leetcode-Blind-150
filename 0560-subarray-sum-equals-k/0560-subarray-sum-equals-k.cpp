class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        unordered_map<int,int> prefixSum;
        prefixSum[0]=1;

        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            ans=ans+prefixSum[sum-k];
            prefixSum[sum]++;
        }
        return ans;
    }
};