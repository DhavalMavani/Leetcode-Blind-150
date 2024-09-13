class Solution {
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector <int>> dp(text1.size()+1,vector <int>(text2.size()+1,0));

        for(int index1=n-1;index1>=0;index1--){
            for(int index2=m-1;index2>=0;index2--){
                if(text1[index1]==text2[index2]){
                    dp[index1][index2]=1+dp[index1+1][index2+1];
                }
                else{
                     dp[index1][index2]= max(dp[index1+1][index2],dp[index1][index2+1] );
                }
            }
        }

        return dp[0][0];
    }
};