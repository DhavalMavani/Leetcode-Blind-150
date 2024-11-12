class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        bool col0=false;

        // i=row, j=col
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    if(j>0) matrix[0][j]=0,matrix[i][0]=0;
                    else col0=true;                        
                }
            }
        }

        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=1;j--) if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
            if(col0) matrix[i][0]=0;
        }
    }
};