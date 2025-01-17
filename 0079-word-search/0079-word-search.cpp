class Solution {
private:
    bool doesExist(int row,int col,int curr){
        if(curr==w.size()) return true;

        if(row>=b.size() || row<0 || col<0 || col>=b[0].size() || b[row][col]!=w[curr]) return false;

        char temp=b[row][col];
        b[row][col]='0';
        bool res= doesExist(row+1,col,curr+1) || doesExist(row,col+1,curr+1) || doesExist(row-1,col,curr+1) || doesExist(row,col-1,curr+1);
        b[row][col]=temp;

        return res;
    }
public:
    vector<vector<char>> b;
    string w;
    bool exist(vector<vector<char>>& board, string word) {
        b=board;
        w=word;
        for (int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(b[i][j]==word[0] && doesExist(i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};