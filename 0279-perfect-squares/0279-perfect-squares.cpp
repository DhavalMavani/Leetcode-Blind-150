class Solution {
public:
    int helper(int res, vector<int> &dp){
        int ans=INT_MAX-10;
        if(res==0) return 0;

        if(dp[res]!=-1) return dp[res];

        for(int i=1;i<=res;i++){
            if(res-i*i>=0)  ans=min(ans,1+helper(res-i*i, dp) );
        }
        return dp[res]=ans;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};