class Solution {
private:
    void NQueens(int n,vector<string> board,int col,
                vector <bool> leftRow,vector <bool> upperLeftDiagonal,vector <bool> lowerLeftDiagonal)
    {
        if(col==n){
            ans.emplace_back(board);
            return;
        }
        for(int r1=0;r1<n;r1++){
            if( !leftRow[r1] && !upperLeftDiagonal[n-1-r1+col] && !lowerLeftDiagonal[r1+col] ){
                board[r1][col]='Q';
                leftRow[r1]=true,upperLeftDiagonal[n-1-r1+col]=true,lowerLeftDiagonal[r1+col]=true;
                NQueens(n,board,col+1,leftRow,upperLeftDiagonal,lowerLeftDiagonal);
                board[r1][col]='.';
                leftRow[r1]=false,upperLeftDiagonal[n-1-r1+col]=false,lowerLeftDiagonal[r1+col]=false;
            }
        }
    }    
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        string st(n,'.');
        vector <bool> leftRow(n,false),upperLeftDiagonal(2*n-1,false),lowerLeftDiagonal(2*n-1,false);
        vector<string> board(n,st);
        NQueens(n,board,0,leftRow,upperLeftDiagonal,lowerLeftDiagonal);
        return ans;
    }
};