class Solution {
public:
    int helper(string word1,string word2,int i1,int i2,vector<vector<int>>& dp){
        if(i1==word1.size() || i2==word2.size()){
            return 0;
        }

        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }

        int c=INT_MIN;
        if(word1[i1]==word2[i2]){
            return 1+ helper(word1,word2,i1+1,i2+1,dp);
        }

        int a=helper(word1,word2,i1+1,i2,dp);
        int b=helper(word1,word2,i1,i2+1,dp);

        return dp[i1][i2]= max(a,b);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size(),vector<int>(word2.size(),-1) );
        return word1.size()+ word2.size() - (2* helper(word1,word2,0,0,dp));
    }
};