class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), dest=n*n-1;
        vector<int> vis(n*n,false);
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({grid[0][0],0});
        vis[0]=true;
        while(!pq.empty()){
            auto [time,cell]=pq.top();
            pq.pop();
            if(cell==dest) return time;
            int x=cell/n,y=cell%n;
            int dirs[]={0,-1,0,1,0};
            for(int i=0;i<4;i++){
                int nx=x+dirs[i],ny=y+dirs[i+1], nc=nx*n+ny;
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nc]){
                    vis[nc]=true;
                    pq.push({max(grid[nx][ny],time),nc});
                }
            }
        }
        return 0;
    }
};