class Solution {
public:
    bool doesExist(int row,int col,int curr,vector<vector<char>>& b, string &w){
        if(curr==w.size()) return true;

        if(row>=b.size() || row<0 || col<0 || col>=b[0].size() || b[row][col]!=w[curr]) return false;

        char temp=b[row][col];
        b[row][col]='0';
        bool res= doesExist(row+1,col,curr+1,b,w) || doesExist(row,col+1,curr+1,b,w) || doesExist(row-1,col,curr+1,b,w) || doesExist(row,col-1,curr+1,b,w);
        b[row][col]=temp;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && doesExist(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};