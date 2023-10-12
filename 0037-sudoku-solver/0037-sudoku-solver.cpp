
// int area= (i/3)*3 + (j/3);

class Solution {
private:
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& area, int rowNo ){
        // i==colNo

        
        if(rowNo>=9){
            return true;
        }

        for(int i=0;i<9;i++){
            
            if(board[rowNo][i]!='.'){
                continue;
            }
            else{
                for(int x=1;x<=9;x++){
                    int areaNo= (rowNo/3)*3 + (i/3);
                    if(row[rowNo][x-1]==false && col[i][x-1]==false && area[areaNo][x-1]==false ){
                        board[rowNo][i]='0'+x;
                        row[rowNo][x-1]=true;
                        col[i][x-1]=true;
                        area[areaNo][x-1]=true;
                        if( helper(board,row,col,area,rowNo) ){
                            return true;
                        }
                        row[rowNo][x-1]=false;
                        col[i][x-1]=false;
                        area[areaNo][x-1]=false;                    
                        board[rowNo][i]='.';
                    }
                }
                return false;
            }
        }

        return helper(board,row,col,area,rowNo+1);
    }


public:

    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> col(9,vector<bool>(9,false));
        vector<vector<bool>> area(9,vector<bool>(9,false));

        for(int i=0; i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                row[i][ board[i][j]-'0' -1 ]=true;
                col[j][ board[i][j]-'0' -1]=true;

                int areaNo= (i/3)*3 + (j/3);
                area[areaNo][ board[i][j]-'0'-1 ]=true;
            }
        }

        helper(board,row,col,area,0);
        
    }
};