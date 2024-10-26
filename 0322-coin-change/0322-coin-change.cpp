class Solution {
public:
    int helper(vector<int>& coins, int target,int index,vector<vector<int>> &dp){
        if(index>=coins.size()){
            if(target==0) return 0;
            return 1e5;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake= helper(coins,target,index+1,dp);
        int take=1e5;
        if(target-coins[index]>=0) take=1+helper(coins,target-coins[index],index,dp);

        return dp[index][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins,amount,0,dp);
        if(ans==1e5) return -1;
        return ans;
        
    }
};