class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans=0;
        int r=grid.size(),c=grid[0].size();

        for(int i=0;i<c;i++){
            for(int j=1;j<r;j++){
                if(grid[j][i]<=grid[j-1][i]){
                    ans+=grid[j-1][i]-grid[j][i]+1;
                    grid[j][i]+=grid[j-1][i]-grid[j][i]+1;
                }
            }
        }
        return ans;
    }
};