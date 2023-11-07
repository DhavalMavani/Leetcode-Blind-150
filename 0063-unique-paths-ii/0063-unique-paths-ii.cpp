class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid,int r,int c,vector<vector<int>>& dp){

        if(r==obstacleGrid.size()-1 && c==obstacleGrid[0].size()-1){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int a=0,b=0;
        if(r+1<obstacleGrid.size() && !obstacleGrid[r+1][c] ){
            a=dfs(obstacleGrid,r+1,c,dp);
        }

        if(c+1<obstacleGrid[0].size() && !obstacleGrid[r][c+1]){
            b=dfs(obstacleGrid,r,c+1,dp);
        }

        return dp[r][c]=a+b;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid[0][0] ){
            return 0;
        }

        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return dfs(obstacleGrid,0,0,dp);
    }
};