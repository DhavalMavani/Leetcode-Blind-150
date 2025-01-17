class Solution {
public:
    int helper(vector<int>& jobDifficulty, int cut, int ind,vector<vector<int>> &dp){
        int n=jobDifficulty.size()-1, ans=INT_MAX,maxi=-1e9;
        if(ind==n+1) return 0;
        if(cut==0) return 1e9;

        if(dp[ind][cut]!=-1) return dp[ind][cut];
            
        for(int i=ind; i<= n- (cut-1); i++){
            maxi=max(maxi,jobDifficulty[i]);
            ans=min(ans,maxi+ helper(jobDifficulty,cut-1,i+1,dp) );
        }
        return dp[ind][cut]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n, vector<int>(d+1,-1));
        return helper(jobDifficulty,d,0,dp);
    }
};
