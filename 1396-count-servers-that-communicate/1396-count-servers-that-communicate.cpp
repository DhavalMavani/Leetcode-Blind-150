class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),ans=0;
        vector<int> row(r,0);
        vector<int> col(c,0);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] && (row[i]>1 || col[j]>1)) ans++;
            }
        }

        return ans;
    }
};