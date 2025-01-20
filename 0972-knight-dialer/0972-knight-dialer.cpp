class Solution {
public:
    vector<vector<int>> move={{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int m=1e9+7;
    int helper(int curr, int jump,vector<vector<int>> &dp){
        if(jump==0) return 1;
        
        if(dp[curr][jump]!=-1) return dp[curr][jump];
        long ans=0;
        for(auto& i: move[curr]) ans+=helper(i,jump-1,dp);
        
        return dp[curr][jump]=ans%m;
    }
    int knightDialer(int n) {
        long ans=0;
        vector<vector<int>> dp(10,vector<int>(n,-1));
        for(int i=0;i<10;i++) ans+=helper(i,n-1,dp);
        return ans%m;
    }
};