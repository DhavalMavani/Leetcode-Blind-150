class Solution {
public:
    long long helper(int i, int k,vector<int>& a, vector<int>& b,vector<vector<long long>> &dp){
        if(k>=4) return 0;
        if(i==b.size()) return -5e10;
        if(dp[i][k] != -5e10) return dp[i][k];

        return dp[i][k]=max(helper(i+1,k,a,b,dp), (long long)a[k]*b[i] + helper(i+1,k+1,a,b,dp) );
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(b.size(),vector<long long>(4,-5e10));
        return helper(0,0,a,b,dp);
    }
};