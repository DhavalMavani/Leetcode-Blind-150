class Solution {
public:

    int dfs(string& s,vector<string>& dictionary, int index,vector<int>& dp){
        if(index==s.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }
        
        int a=1+dfs(s,dictionary,index+1,dp);
        int b=INT_MAX;
        for(auto &i: dictionary){
            if(s.substr(index,i.size())==i ){
                b=min(b,dfs(s,dictionary,index+i.size(),dp) );
            }
        }
        return dp[index]= min(a,b);

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(),-1);
        return dfs(s,dictionary,0,dp);
    }
};