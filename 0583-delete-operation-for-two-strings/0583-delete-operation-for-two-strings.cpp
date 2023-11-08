class Solution {
public:
    int helper(string word1,string word2,int i1,int i2,vector<vector<int>>& dp){
        if(i1==word1.size() || i2==word2.size()){
            return 0;
        }

        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }

        if(word1[i1]==word2[i2]){
            return dp[i1][i2] = 1+ helper(word1,word2,i1+1,i2+1,dp);
        }

        int a=helper(word1,word2,i1+1,i2,dp);
        int b=helper(word1,word2,i1,i2+1,dp);

        return dp[i1][i2]= max(a,b);
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp (m,vector<int>(n,-1) );
        return m+ n - (2* helper(word1,word2,0,0,dp));
    }
};