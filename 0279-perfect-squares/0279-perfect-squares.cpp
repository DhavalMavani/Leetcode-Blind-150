class Solution {
public:
    int helper(int res, vector<int> &dp){
        if(res==0){
            return 0;
        }
        if(dp[res]!=-1){
            return dp[res];
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=res;i++){
            if(res-i*i>=0){
                ans=min(ans,1+helper(res-i*i, dp) );
            }            
        }
        return dp[res]=ans;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};