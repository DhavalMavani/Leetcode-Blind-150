class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &grid){
        if(r==grid.size() || c== grid[0].size() || r<0 || c<0 || grid[r][c]!=1) return;

        grid[r][c]=2;
        dfs(r+1,c,grid);
        dfs(r,c+1,grid);
        dfs(r-1,c,grid);
        dfs(r,c-1,grid);
    }
    int countIslands(vector<vector<int>> grid){
        int num=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    num++;
                    dfs(i,j,grid);
                }
            }
        }

        return num;
    }
    int minDays(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),ans=2;
        
        int a=countIslands(grid);
        if(a==0 || a>=2) return 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int num=countIslands(grid);
                    if(num==0 || num>=2) return 1;
                    grid[i][j]=1;
                }
            }
        }
        
        return ans;
    }
};