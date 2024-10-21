class Solution {
public:
    vector<vector<int>> dp;
    int helper(int l,int r,vector<int>& nums){
        if(l>r) return 0;

        if(dp[l][r]!=-1)return dp[l][r];
        int ans=-1;
        for(int i=l;i<=r;i++) ans=max(ans,nums[l-1]*nums[i]*nums[r+1] + helper(l,i-1,nums) + helper(i+1,r,nums) );
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.emplace(nums.begin(),1);
        nums.emplace_back(1);
        int n=nums.size();
        dp.resize(n-1,vector<int>(n-1,-1));
        return helper(1,nums.size()-2,nums);
    }
};