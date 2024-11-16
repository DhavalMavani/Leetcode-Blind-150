class Solution {
public: 
    int n,ans=0;
    vector<bool> leftRow,upperLeftDiagonal,lowerLeftDiagonal;
    void helper(int col){
        if(col==n){
            ans++;
            return;
        }
        for(int r=0;r<n;r++){
            if(!leftRow[r] && !upperLeftDiagonal[n-1-r+col] && !lowerLeftDiagonal[r+col]){
                leftRow[r]=true,upperLeftDiagonal[n-1-r+col]=true,lowerLeftDiagonal[r+col]=true;
                helper(col+1);
                leftRow[r]=false,upperLeftDiagonal[n-1-r+col]=false,lowerLeftDiagonal[r+col]=false;
            }
        }
    }

    int totalNQueens(int N) {
        n=N;
        leftRow.resize(n,false);
        upperLeftDiagonal.resize(2*n-1,false);
        lowerLeftDiagonal.resize(2*n-1,false);
        helper(0);
        return ans;
    }
};