class Solution {
public:
    int maxLen;
    int solve(int index,int diff,vector<int>& rods,vector<vector<int>> &dp){
        if(abs(diff)>2500) return INT_MIN;
        if(index==rods.size()){
            if(diff==0)  return 0;
            return INT_MIN;
        }
        if(dp[index][diff+2500]!=-1) return dp[index][diff+2500];

        int dontAdd=solve(index+1,diff,rods,dp);
        int addLeft= rods[index] + solve(index+1,diff + rods[index] ,rods,dp);
        int addRight= rods[index] + solve(index+1,diff - rods[index] ,rods,dp);

        return dp[index][diff+2500]=max(dontAdd,max(addLeft,addRight));
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<vector<int>> dp(n,vector<int>(5001,-1) );
        return solve(0,0,rods,dp)/2;
    }
};