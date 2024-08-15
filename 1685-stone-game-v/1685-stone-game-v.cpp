class Solution {
public:
    int calcScore(int l,int r,vector<int>& stoneValue,vector<vector<int>> &dp,vector<int> &prefixSum){
        if(l>=r) return 0;
        
        if(dp[l][r]!=INT_MIN) return dp[l][r];
        int total=prefixSum[r]-prefixSum[l]+stoneValue[l];
        int leftSum=0,rightSum=total, ans=INT_MIN;

        for(int i=l;i<r;i++){
            leftSum+=stoneValue[i];
            rightSum-=stoneValue[i];
            if(leftSum>rightSum){
                ans=max(ans,rightSum+calcScore(i+1,r,stoneValue,dp,prefixSum));
            }
            else if(leftSum<rightSum){
                ans=max(ans,leftSum+calcScore(l,i,stoneValue,dp,prefixSum));
            }
            else{
                ans=max(ans,leftSum+calcScore(l,i,stoneValue,dp,prefixSum));
                ans=max(ans,rightSum+calcScore(i+1,r,stoneValue,dp,prefixSum));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> prefixSum(n,0);
        prefixSum[0]=stoneValue[0];
        for(int i=1;i<n;i++) prefixSum[i]=prefixSum[i-1]+stoneValue[i];
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return calcScore(0,n-1,stoneValue,dp,prefixSum);
    }
};