class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int calcCost(int index,int wallsPainted,vector<int> &cost,vector<int> &time){
        if(wallsPainted>=n ) return 0;
        if(index==n) return 1e6*250+1;
        if(dp[index][wallsPainted]!=-1e9) return dp[index][wallsPainted];

        int paintWall=cost[index]+calcCost(index+1,wallsPainted+1+time[index],cost,time);
        int dontPaintWall=calcCost(index+1,wallsPainted,cost,time);

        return dp[index][wallsPainted]=min(paintWall,dontPaintWall);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        dp.resize(n,vector<int>(n,-1e9));
        return calcCost(0,0,cost,time);
    }
};