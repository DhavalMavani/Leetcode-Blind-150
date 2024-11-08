class Solution {
public:
    int n1,n2,n3;
    vector<vector<int>> dp;
    string a,b,c;
    bool interleaving(int i1, int i2){
        if( i2==n2 && i1==n1) return true;

        if(dp[i1][i2] !=-1) return dp[i1][i2];

        if(i1<n1 && a[i1]==c[i1+i2]) if (interleaving(i1+1,i2)) return dp[i1][i2]=1;
        if(i2<n2 && b[i2]==c[i1+i2]) if (interleaving(i1,i2+1)) return dp[i1][i2]=1;
        
        return dp[i1][i2] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n3!= n1+n2) return false;
        a=s1,b=s2,c=s3;
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return interleaving(0,0);
    }
};