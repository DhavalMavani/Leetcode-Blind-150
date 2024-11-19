class Solution {
public:
    int dfs(int x,int y,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]!=1) return 0;

        grid[x][y]=2;
        int curr=1;
        curr+=dfs(x+1,y,grid);
        curr+=dfs(x-1,y,grid);
        curr+=dfs(x,y+1,grid);
        curr+=dfs(x,y-1,grid);

        return curr;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),ans=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int area=dfs(i,j,grid);
                    ans=max(ans,area);
                }
            }
        }

        return ans;
    }
};