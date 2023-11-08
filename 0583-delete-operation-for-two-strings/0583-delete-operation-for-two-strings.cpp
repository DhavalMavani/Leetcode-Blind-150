class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        
        int lcs = helper(word1, word2, m, n);
        int steps = (m-lcs) + (n-lcs);
        return steps;
    }
    
    int helper(string word1, string word2, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        //Intializing the matrix
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        //solving the subproblems
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};