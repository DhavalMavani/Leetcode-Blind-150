class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n*n, vector<bool>(n*n,false));
        q.push({0,1});
        visited[0][1]=true;

        int moves=0,head_end=n*n-1, tail_end=n*n-2;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int tail=q.front().first,head=q.front().second;
                q.pop();
                if(tail==tail_end && head==head_end) return moves;
                // x=row, y=col
                int tail_X=tail/n, tail_Y=tail%n, head_X=head/n, head_Y=head%n;

                if(head_Y+1<n && tail_X==head_X && !grid[head_X][head_Y+1] && !visited[head][head+1] ){
                    visited[head][head+1]=true;
                    q.push({head, head+1}); // move right horizontally
                }
                else if(head_Y+1<n && tail_Y==head_Y && !grid[tail_X][tail_Y+1] && !grid[head_X][head_Y+1] && !visited[tail+1][head+1]){
                    visited[tail+1][head+1]=true;
                    q.push({tail+1, head+1 }); // move right vertically
                }

                if(head_X+1<n && tail_Y==head_Y && !grid[head_X+1][head_Y] && !visited[head][head+n]){
                    visited[head][head+n]=true;
                    q.push({head, head+n }); // move down vertically
                }
                else if(head_X+1<n && tail_X==head_X && !grid[tail_X+1][tail_Y] && !grid[head_X+1][head_Y] && !visited[tail+n][head+n]){
                    visited[tail+n][head+n]=true;
                    q.push({tail+n, head+n }); // move down horizontally
                }

                if(head_X+1<n && tail_X==head_X && !grid[tail_X+1][tail_Y] && !grid[head_X+1][head_Y] && !visited[tail][tail+n] ){
                    visited[tail][tail+n]=true;
                    q.push({tail, tail+n }); // Rotate clockwise
                }
                else if(head_Y+1<n && tail_Y==head_Y && !grid[tail_X][tail_Y+1] && !grid[head_X][head_Y+1] && !visited[tail][tail+1] ){
                    visited[tail][tail+1]=true;
                    q.push({tail, tail+1 }); // Rotate counterclockwise
                }
            }
            moves++;
        }

        return -1;


    }
};