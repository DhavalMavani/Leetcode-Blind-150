class Solution {
public:

    int lcs(string &s1, string &s2, int i1, int i2,vector<vector<int>> &dp){
        if(i1==s1.size() || i2==s1.size() ) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s1[i1]==s2[i2]) return dp[i1][i2]=1+lcs(s1,s2,i1+1,i2+1,dp);

        else return dp[i1][i2]=max(lcs(s1,s2,i1+1,i2,dp), lcs(s1,s2,i1,i2+1,dp));

    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return lcs(s,s2,0,0,dp);
    }
};