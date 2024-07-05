class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        int x_dirs[]={-1,0,1,-1,1,-1,0,1};
        int y_dirs[]={-1,-1,-1,0,0,1,1,1};


        queue<int> q;
        q.emplace(0);
        grid[0][0]=2;
        int len=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int t=q.front();
                q.pop();
                int x=t/n, y=t%n;

                if(x==n-1 && y==n-1) return len;

                for(int j=0;j<8;j++){
                    int a=x+x_dirs[j], b=y+y_dirs[j];
                    if(a>=0 && b>=0 && a<n && b<n && grid[a][b]==0){
                        q.emplace(a*n+b);
                        grid[a][b]=2;
                    }
                }
            }
            len++;
        }

        return -1;
    }
};