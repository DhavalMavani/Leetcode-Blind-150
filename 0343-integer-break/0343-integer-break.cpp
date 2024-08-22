class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n<=3) return n;
        int ans=1;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<=n-1;i++) ans= max(ans, i * solve(n-i, dp) );
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        if(n==2 || n==3) return n-1;
        return solve(n,dp);
    }
};