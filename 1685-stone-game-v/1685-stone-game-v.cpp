class Solution {
public:
    int calcScore(int l,int r,vector<int>& stoneValue,vector<vector<int>> &dp){
        if(l>=r) return 0;
        
        if(dp[l][r]!=INT_MIN) return dp[l][r];
        int total=0;
        for(int i=l;i<=r;i++) total+=stoneValue[i];

        int leftSum=0,rightSum=total, ans=INT_MIN;

        for(int i=l;i<r;i++){
            leftSum+=stoneValue[i];
            rightSum-=stoneValue[i];
            if(leftSum>rightSum){
                ans=max(ans,rightSum+calcScore(i+1,r,stoneValue,dp));
            }
            else if(leftSum<rightSum){
                ans=max(ans,leftSum+calcScore(l,i,stoneValue,dp));
            }
            else{
                ans=max(ans,leftSum+calcScore(l,i,stoneValue,dp));
                ans=max(ans,rightSum+calcScore(i+1,r,stoneValue,dp));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return calcScore(0,n-1,stoneValue,dp);
    }
};