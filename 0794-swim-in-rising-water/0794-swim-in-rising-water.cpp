class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> vis(n*n,false);
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({grid[0][0],0});
            vis[0]=true;
        while(!pq.empty()){
            auto [time,cell]=pq.top();
            pq.pop();
            if(cell==n*n-1) return time;
            int x=cell/n,y=cell%n;
            int dirs[]={0,-1,0,1,0};
            for(int i=0;i<4;i++){
                int nx=x+dirs[i],ny=y+dirs[i+1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx*n+ny]){
                    vis[nx*n+ny]=true;
                    pq.push({max(grid[nx][ny],time),nx*n+ny});
                }
            }
        }
        return 0;
    }
};