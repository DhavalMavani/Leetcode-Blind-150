class Solution {
public:
    bool canWin(int n,vector<int> &dp){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if( !canWin(n-i*i,dp) ) return dp[n]=1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return canWin(n,dp);
    }
};