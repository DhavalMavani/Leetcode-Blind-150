class Solution {
private:
    int ans;
    vector <vector<int>> dp;
    int targetSum (vector<int>& nums, int target, int index){
        if(index==nums.size()){
            if(target==ans) return 1;
            return 0;
        }
        if(dp[index][target+1000]!=-1) return dp[index][target+1000];
        
        int a=targetSum(nums,target-nums[index],index+1 );
        int b=targetSum(nums,target+nums[index],index+1 );

        return dp[index][target+1000]=a+b;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ans=target;
        dp.resize(nums.size(), vector <int> (2000,-1) ); 
        return targetSum(nums,0,0);
    }
};