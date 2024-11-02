class Solution {

private:
    int decode(string &s,int index, vector <int> &dp){
        if(index==s.size()) return 1;
        
        if(dp[index]!=-1) return dp[index];
        
        if(int(s[index]-'0')==0) return 0;

        int a=decode(s,index+1,dp);
        int b=0;
        if(index+1<s.size() && stoi(s.substr(index,2))<=26) b=decode(s,index+2,dp);
        
        return dp[index]=a+b;
    }
public:
    vector <vector<int>> ans;
    int numDecodings(string s) {
        vector <int> dp(s.size(),-1);
        return decode(s,0,dp);
    }
};