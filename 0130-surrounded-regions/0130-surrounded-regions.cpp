class Solution {
private:
void dfs(vector<vector<char>>& board,int r,int c){
    if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]=='O' ){
        board[r][c]='T';
        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);
    }
}

public:
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();

        for(int i=0;i<col;i++){
            if(board[row-1][i]=='O') dfs(board,row-1,i);
            if(board[0][i]=='O') dfs(board,0,i);
        }

        for(int i=0;i<row;i++){
            if(board[i][col-1]=='O') dfs(board,i,col-1);
            if(board[i][0]=='O') dfs(board,i,0);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='T') board[i][j]='O';
            }
        }   
    }
};