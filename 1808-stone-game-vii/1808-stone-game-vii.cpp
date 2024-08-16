class Solution {
public:
    int calcDiff(int l,int r,vector<int>& stones,int sum,vector<vector<int>> &dp){
        if(l>=r) return 0;
        if(dp[l][r]!=INT_MIN) return dp[l][r];
        int opt1= sum-stones[l]-calcDiff(l+1,r,stones,sum-stones[l],dp);
        int opt2= sum-stones[r]-calcDiff(l,r-1,stones,sum-stones[r],dp);
        return dp[l][r]=max(opt1,opt2);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size(),sum=0;
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int i=0;i<n;i++) sum+=stones[i];
        return calcDiff(0,n-1,stones,sum,dp);
    }
};