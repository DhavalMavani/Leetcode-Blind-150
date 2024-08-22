class Solution {
public:
    int sum;
    int solve(int index,int diff,vector<int>& rods,vector<vector<int>> &dp){
        if(abs(diff)>sum) return INT_MIN;
        if(index==rods.size()){
            if(diff==0)  return 0;
            return INT_MIN;
        }
        if(dp[index][diff+sum]!=-1) return dp[index][diff+sum];

        int dontAdd=solve(index+1,diff,rods,dp);
        int addLeft= rods[index] + solve(index+1,diff + rods[index] ,rods,dp);
        int addRight= rods[index] + solve(index+1,diff - rods[index] ,rods,dp);

        return dp[index][diff+sum]=max(dontAdd,max(addLeft,addRight));
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        sum = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(n,vector<int>(sum+1,-1) );
        sum/=2;
        return solve(0,0,rods,dp)/2;
    }
};