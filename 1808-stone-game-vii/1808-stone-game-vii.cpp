class Solution {
public:
    int calcDiff(int l,int r,vector<int>& stones,vector<int> &prefix,vector<vector<int>> &dp){
        if(l>=r) return 0;
        int total=prefix[r]-prefix[l]+stones[l];
        if(dp[l][r]!=INT_MIN) return dp[l][r];
        int opt1= total-stones[l]-calcDiff(l+1,r,stones,prefix,dp);
        int opt2= total-stones[r]-calcDiff(l,r-1,stones,prefix,dp);
        return dp[l][r]=max(opt1,opt2);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n);
        prefix[0]=stones[0];
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+stones[i];
        return calcDiff(0,n-1,stones,prefix,dp);
    }
};