class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(), last_sq=n*n, ind=1, moves=0;
        bool leftToRight=true;
        vector<int> newBoard(last_sq+1);
        for(int i=n-1;i>=0;i--){
            if(leftToRight){
                for(int j=0;j<n;j++){
                    newBoard[ind]=board[i][j];
                    ind++;
                }
                leftToRight=false;
            }
            else{
                for(int j=n-1;j>=0;j--){
                    newBoard[ind]=board[i][j];
                    ind++;
                }
                leftToRight=true;
            }
        }

        queue<int> q;
        q.emplace(1);
        newBoard[1]=last_sq+1;

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int currSquare=q.front();
                q.pop();
                if(currSquare==last_sq) return moves;

                for(int j=currSquare+1;j<=min(currSquare+6,last_sq); j++){
                    if(newBoard[j]==-1){
                        q.emplace(j);
                        newBoard[j]=401;
                    }
                    else if(newBoard[j]!=401){
                        q.emplace(newBoard[j]);
                        newBoard[j]=401;
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};