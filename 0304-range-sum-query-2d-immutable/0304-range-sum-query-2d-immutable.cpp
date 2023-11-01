class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> sum (matrix.size()+1,vector<int> (matrix[0].size()+1,0 ));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]+matrix[i][j]-sum[i][j];
            }
        }
        prefixSum=sum;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2+1][col2+1] - prefixSum[row2+1][col1] - prefixSum[row1][col2+1] + prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */