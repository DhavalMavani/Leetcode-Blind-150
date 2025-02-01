class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ansStr=s.substr(0,1);
        vector<vector<bool>> dp(n,vector <bool>(n,false));
        
        for(int i=0;i<n;i++) dp[i][i]=true;
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                ansStr=s.substr(i,2);
            }
            else dp[i][i+1]=false;
        }

        for(int len= 3; len<=s.size(); len++){
            for(int strPos=0;strPos<=s.size()-len;strPos++){
                int endPos=len+strPos-1;
                if(s[strPos]==s[endPos] && dp[strPos+1][endPos-1]){
                    dp[strPos][endPos]=true;
                    if(len>ansStr.size()) ansStr=s.substr(strPos,len);
                }
                else dp[strPos][endPos]=0;
            }
        }
        return ansStr;
    }
};