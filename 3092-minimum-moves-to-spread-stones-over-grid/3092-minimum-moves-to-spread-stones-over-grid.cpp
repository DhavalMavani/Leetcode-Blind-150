class Solution {
public:
    vector<int> zero,extra;
    int moves=1e9;
    void dfs(vector<vector<int>>& grid, int ind, int currSteps){
        if(ind>=zero.size()){
            moves=min(moves,currSteps);
            return;
        }

        int a=zero[ind]/3, b=zero[ind]%3;
        for(int i=0;i<extra.size();i++){
            int x=extra[i]/3, y=extra[i]%3;
            if(grid[x][y]==1) continue;
            grid[x][y]--;
            dfs(grid,ind+1,currSteps+abs(x-a)+abs(y-b) );
            grid[x][y]++;
        }
    }
    int minimumMoves(vector<vector<int>>& grid) {
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0) zero.emplace_back(i*3+j);
                else if(grid[i][j]>1) extra.emplace_back(i*3+j);
            }
        }
        dfs(grid,0,0);

        return moves;
    }
};