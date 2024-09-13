class Solution {

    int lsc(string &text1, string &text2,int index1, int index2,vector<vector <int>> &dp){
        if(index1==text1.size() || index2==text2.size()){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        int a=0,b=0;
        if(text1[index1]==text2[index2]){
            a=1+lsc(text1,text2,index1+1,index2+1,dp);
        }
        else{
            b=max(lsc(text1,text2,index1+1,index2,dp),lsc(text1,text2,index1,index2+1,dp) );
        }
        return dp[index1][index2]= a+b;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector <int>> dp(text1.size(),vector <int>(text2.size(),-1));
        return lsc(text1,text2,0,0,dp);
    }
};