class Solution {
public:

    int calcStones(int l,int r,vector<int> &piles,vector<vector<int>> &dp){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int a=piles[l] + min( calcStones(l+2,r,piles,dp), calcStones(l+1,r-1,piles,dp) );
        int b=piles[r] + min( calcStones(l+1,r-1,piles,dp), calcStones(l,r-2,piles,dp) );

        return dp[l][r]=max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size(),total=0;
        for(int i=0;i<n;i++) total+=piles[i];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int alice= calcStones(0,n-1,piles,dp);
        return alice>total-alice;
    }
};