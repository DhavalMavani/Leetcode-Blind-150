class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row,col;
        int r=matrix.size(),c=matrix[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }

        for(auto &i: row){
            for(int j=0;j<c;j++) matrix[i][j]=0;
        }

        for(auto &i: col){
            for(int j=0;j<r;j++) matrix[j][i]=0;
        }
        
    }
};