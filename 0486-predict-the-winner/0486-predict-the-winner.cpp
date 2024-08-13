class Solution {
public:
    int helper(vector<int>& nums, int l,int r,vector<vector<int>> &dp){
        if(l>r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        int a=nums[l]+ min ( helper(nums,l+2,r,dp), helper(nums,l+1,r-1,dp)  );
        int b=nums[r]+ min ( helper(nums,l+1,r-1,dp), helper(nums,l,r-2,dp)  );

        return dp[l][r]=max(a,b);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total=0,n=nums.size();
        for(auto &i: nums) total+=i;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans= helper(nums,0,n-1,dp);
        if(ans>=total-ans) return true;
        return false;

    }
};