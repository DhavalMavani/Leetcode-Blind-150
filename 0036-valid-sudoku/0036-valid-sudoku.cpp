class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int size=board.size();

        vector<vector<bool>> mprow(board.size(), vector <bool> (board[0].size(),0));
        vector<vector<bool>> mpcol(board.size(), vector <bool> (board[0].size(),0));
        vector<vector<bool>> mpsub(board.size(), vector <bool> (board[0].size(),0));
        
        for (int i=0; i<size; i++){
            
            for (int j=0;j<size;j++){
                int area= (i/3)*3 + (j/3);
                if (board[i][j] == '.'){
                    continue;
                }
                else if( mprow[i][board[i][j]-'0'-1] || mpcol[j][ board[i][j]-'0'-1 ] || mpsub[area][ board[i][j]-'0'-1 ] ){
                    return false;
                }
                else{
                    mprow[i][ board[i][j]-'0'-1]=1;
                    mpcol[j][ board[i][j]-'0'-1]=1;
                    mpsub[area][ board[i][j]-'0'-1 ]=1;
                }
            }
        }        

        return true;
    }
};