class Solution {
public:
    int helper(string &s,int l,vector<vector<bool>> &dp, vector<int>& dp2){
        int ans=1e9,n=s.size();
        if(l==n) return 0;
        if(dp2[l]!=-1) return dp2[l];

        for(int i=l;i<n;i++){
            if(dp[l][i]) ans=min(ans,1+helper(s,i+1,dp,dp2));
        }
        return dp2[l]=ans;
    }

    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=1;i<n;i++) if(s[i-1]==s[i]) dp[i-1][i]=1;

        for(int len=3;len<=n;len++){
            for(int ind=len-1;ind<n;ind++){
                if(s[ind-len+1]==s[ind] && dp[ind-len+2][ind-1]) dp[ind-len+1][ind]=1;
            }
        }
        vector<int> dp2(n,-1);

        return helper(s,0,dp,dp2)-1;
    }
};