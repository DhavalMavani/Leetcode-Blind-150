class Solution {
public:
    bool isPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int helper(string &s,int index,vector<int> &dp){
        if(index>=s.size()) return 0;
        int ans=INT_MAX;

        if(dp[index]!=-1) return dp[index];

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                ans=min(ans, 1+helper(s,i+1,dp) );
            }
        }

        return dp[index]=ans;
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return helper(s,0,dp)-1;
    }
};