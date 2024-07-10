class Solution {
public:
    void dfs(vector<int> &zero,vector<int> &extra,vector<vector<int>>& grid, int &moves, int ind, int currSteps){
        if(ind>=zero.size()){
            moves=min(moves,currSteps);
            return;
        }

        int a=zero[ind]/3, b=zero[ind]%3;
        for(int i=0;i<extra.size();i++){
            int x=extra[i]/3, y=extra[i]%3;
            if(grid[x][y]==1) continue;
            grid[x][y]--;
            dfs(zero,extra,grid,moves,ind+1,currSteps+abs(x-a)+abs(y-b) );
            grid[x][y]++;
        }
    }
    int minimumMoves(vector<vector<int>>& grid) {
        int ans=0;
        vector<int> zero,extra;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0) zero.emplace_back(i*3+j);
                else if(grid[i][j]>1) extra.emplace_back(i*3+j);
            }
        }
        int moves=1e9;
        dfs(zero,extra,grid,moves,0,0);

        return moves;
    }
};