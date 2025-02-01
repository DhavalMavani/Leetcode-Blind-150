class Solution {

private:
    bool doesMatch(string &s, string &p,int i1,int i2,vector<vector<int>> &dp){
        if(i1==s.size() && i2==p.size()) return true;

        if(i1>s.size() || i2>p.size()) return false;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s[i1]==p[i2] || p[i2]=='.'){
            if(doesMatch(s,p,i1+1,i2+1,dp)) return dp[i1][i2]=true;
        } 
        else if(p[i2]=='*' && (p[i2-1]=='.' || p[i2-1]==s[i1])){
            if(doesMatch(s,p,i1+1,i2+1,dp)|| doesMatch(s,p,i1+1,i2,dp)) return dp[i1][i2]=true;
        }
        
        if( (i2+1<p.size() && p[i2+1]=='*') || p[i2]=='*'){
            if(doesMatch(s,p,i1,i2+1,dp)) return dp[i1][i2]=true;
        }

        return dp[i1][i2]=false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return doesMatch(s,p,0,0,dp);
    }
};