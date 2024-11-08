class Solution {
private:
    bool interleaving(string &s1,string &s2,string &s3,int i1, int i2,vector <vector<int>> &dp){
        if( i2==n2 && i1==n1) return true;

        if(dp[i1][i2] !=-1) return dp[i1][i2];

        bool a=false,b=false;
        if(i1<n1 && s1[i1]==s3[i1+i2]) a=interleaving(s1,s2,s3,i1+1,i2,dp);
        if(i2<n2 && s2[i2]==s3[i1+i2]) b=interleaving(s1,s2,s3,i1,i2+1,dp);
        
        return dp[i1][i2] = a||b;
    }
public:
    int n1,n2,n3;
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n3!= n1+n2) return false;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return interleaving(s1,s2,s3,0,0,dp);
    }
};