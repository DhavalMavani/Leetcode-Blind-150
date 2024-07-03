class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(), dist=0;
        int dirs[]={0,1,0,-1,0};

        queue<pair<int,int>> q;
        q.push({0,k});

        vector<vector<bool>> visited(m*n+1, vector<bool>(k+1,false));
        visited[0][k]=true;

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int t=q.front().first, currK=q.front().second;
                q.pop();
                int x=t/n, y=t%n;
                if(x==m-1 && y==n-1) return dist;

                for(int j=0;j<4;j++){
                    int a=x+dirs[j], b=y+dirs[j+1];
                    if(a>=0 && b>=0 && a<m && b<n ){
                        int newK=currK - grid[a][b];
                        if(newK>=0 && !visited[a*n+b][newK]){
                            q.push({a*n+b,newK});
                            visited[a*n+b][newK]=true;
                        }
                    }
                }
                
            }
            dist++;
        }
        return -1;
    }
};