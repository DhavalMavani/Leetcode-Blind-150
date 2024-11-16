class Solution {
public: 
    int n,ans=0;
    void helper(int col,vector <bool> &leftRow,vector <bool> &upperLeftDiagonal,vector <bool> &lowerLeftDiagonal){
        if(col==n){
            ans++;
            return;
        }
        for(int r=0;r<n;r++){
            if(!leftRow[r] && !upperLeftDiagonal[n-1-r+col] && !lowerLeftDiagonal[r+col]){
                leftRow[r]=true,upperLeftDiagonal[n-1-r+col]=true,lowerLeftDiagonal[r+col]=true;
                helper(col+1,leftRow,upperLeftDiagonal,lowerLeftDiagonal);
                leftRow[r]=false,upperLeftDiagonal[n-1-r+col]=false,lowerLeftDiagonal[r+col]=false;
            }
        }
    }

    int totalNQueens(int N) {
        n=N;
        vector <bool> leftRow(n,false),upperLeftDiagonal(2*n-1,false),lowerLeftDiagonal(2*n-1,false);
        helper(0,leftRow,upperLeftDiagonal,lowerLeftDiagonal);
        return ans;
    }
};