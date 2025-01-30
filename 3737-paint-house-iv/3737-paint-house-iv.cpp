class Solution {
public:
    long long paintHouse(vector<vector<int>> &cost, int house, int prevColour1, int prevColour2,vector<vector<vector<long long>>> &dp){
        long long ans=LONG_MAX;
        int n=cost.size();

        if( house== n/2) return 0;

        if(dp[house][prevColour1+1][prevColour2+1]!=-1) return dp[house][prevColour1+1][prevColour2+1];
        for(int c1=0;c1<3;c1++){
            if(c1==prevColour1) continue;
            for(int c2=0;c2<3;c2++){
                if(c2==prevColour2 || c1==c2) continue;
                ans=min(ans, cost[house][c1] + cost[n-house-1][c2] + paintHouse(cost,house+1,c1,c2,dp));
            }
        }
        return dp[house][prevColour1+1][prevColour2+1]=ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>> dp(n/2,vector<vector<long long>>(4,vector<long long>(4,-1)));
        return paintHouse(cost,0,-1,-1,dp);
    }
};