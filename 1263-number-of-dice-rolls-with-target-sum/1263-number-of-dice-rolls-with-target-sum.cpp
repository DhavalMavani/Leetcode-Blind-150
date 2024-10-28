class Solution {
public:
    int K,m=1e9+7;
    vector<vector<int>> dp;
    int helper(int currSum,int n){
        if(n==0){
            if(currSum==0) return 1;
            return 0;
        }
        if(dp[currSum][n]!=-1) return dp[currSum][n];
        if(K*n<currSum) return dp[currSum][n]=0;
        
        int ans=0;
        for(int i=1;i<=K;i++) if(i<=currSum) ans=( ans+helper(currSum-i,n-1))%m;

        return dp[currSum][n]=ans;
    }
    int numRollsToTarget(int n, int k, int &target) {
        K=k;
        dp.resize(target+1,vector<int>(n+1,-1));
        return helper(target,n);
    }
};