class Solution {
private:
    void dfs(vector<vector<int>>& heights, int r,int c,vector<vector<bool>>& hasVisited){
        hasVisited[r][c]=true;
        int arrRow[4]={-1,1,0,0};
        int arrCol[4]={0,0,-1,1};
        
        for(int k=0;k<4;k++){
            int a=r+arrRow[k];
            int b=c+arrCol[k];
            if(a>=0 && b>=0 && a<heights.size() && b<heights[0].size() && !hasVisited[a][b]){
                if(heights[a][b]>=heights[r][c]){
                    dfs(heights,a,b,hasVisited);
                }
            }
        }

    }
public:
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int rows=heights.size(),cols=heights[0].size();
        
        vector<vector<bool>> hasVisitedPacific(rows,vector<bool>(cols,false));
        for(int i=0;i<cols;i++){
            if(!hasVisitedPacific[0][i]) dfs(heights,0,i,hasVisitedPacific);
        }
        for(int i=0;i<rows;i++){
            if(!hasVisitedPacific[i][0]) dfs(heights,i,0,hasVisitedPacific);
        }

        vector<vector<bool>> hasVisitedAtlantic(rows,vector<bool>(cols,false));
        for(int i=0;i<cols;i++){
            if(!hasVisitedAtlantic[rows-1][i]) dfs(heights,rows-1,i,hasVisitedAtlantic);
        }
        for(int i=0;i<rows;i++){
            if(!hasVisitedAtlantic[i][cols-1]) dfs(heights,i,cols-1,hasVisitedAtlantic);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(hasVisitedAtlantic[i][j] && hasVisitedPacific[i][j]) ans.push_back({i,j});
            }
        }

        return ans;
    }
};