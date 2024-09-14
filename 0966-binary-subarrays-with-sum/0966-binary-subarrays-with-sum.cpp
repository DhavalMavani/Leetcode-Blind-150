class Solution {
public:

    int subarraysWithSumLessThenK(vector<int>& nums, int s){
        if(s<0) return 0;
        int n=nums.size(),l=0,r=0,sum=0,ans=0;

        while(r<n){
            sum+=nums[r];
            while(sum>s){
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarraysWithSumLessThenK(nums,goal)-subarraysWithSumLessThenK(nums,goal-1);
    }
};