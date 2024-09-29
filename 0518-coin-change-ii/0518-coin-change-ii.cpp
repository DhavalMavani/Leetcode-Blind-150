class Solution {
private:
    int combinations(vector<int>& coins,int target,int index,vector <vector<int>> &dp){
        if(index==coins.size()) return 0;
        if(target==0) return 1;
        if(dp[index][target]!=-1) return dp[index][target];
        
        int a=0,b=0;
        if(target-coins[index]>=0) a=combinations(coins,target-coins[index],index,dp);
        b=combinations(coins,target,index+1,dp);

        return dp[index][target]=a+b;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector <vector<int>> dp (coins.size(),vector<int> (amount+1,-1));
        return combinations(coins,amount,0,dp);
    }
};