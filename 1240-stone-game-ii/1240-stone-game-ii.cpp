class Solution {
public:
    int calcStones(vector<int>& piles, int ind, int m,vector<vector<int>> &dp){
        int n=piles.size();
        if(ind>=n) return 0;
        if(dp[ind][m]!=-1e9) return dp[ind][m];
        int ans=-1e9,sum=0;

        for(int i=ind;i<= min (ind+2*m-1,n-1);i++){
            sum+=piles[i];
            ans=max(ans,sum-calcStones(piles,i+1,max(m,i-ind+1),dp) );
        }
        return dp[ind][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int total=0,n=piles.size();
        for(auto &i: piles) total+=i;
        vector<vector<int>> dp(n,vector<int>(n+1,-1e9));
        return (total+calcStones(piles,0,1,dp))/2;
    }
};