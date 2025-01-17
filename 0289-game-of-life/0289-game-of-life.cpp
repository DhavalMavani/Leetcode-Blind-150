class Solution {
public:
    int countNeighbors(int r,int c, vector<vector<int>>& board){
        int m=board.size(),n=board[0].size(), count=0;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0) continue;
                int x=r+i, y=c+j;

                if(x>=0 && y>=0 && x<m && y<n){
                    if(board[x][y]==1 || board[x][y]==2) count++;
                }

            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int neighbors= countNeighbors(i,j,board);
                if(board[i][j]==1){
                    if(neighbors<2 || neighbors>3) board[i][j]=2;
                }
                else if(neighbors==3) board[i][j]=3;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==3) board[i][j]=1;
            }
        }
    }

};

/*
0 = dead , curr dead -> after dead
1 = alive , curr alive -> after alive
2 = curr alive -> after dead
3 = curr dead -> after alive
*/