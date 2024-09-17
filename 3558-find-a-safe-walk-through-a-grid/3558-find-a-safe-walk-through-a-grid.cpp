class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int r=grid.size(), c=grid[0].size();
        if(grid[0][0]) health--;
        if(health==0) return false;

        queue<pair<int,int>> q; // { cell, health }
        q.push({0,health});

        vector<vector<bool>> visited(r*c, vector<bool>(health+1,false));
        visited[0][health]=true;

        int dirs[]={0,1,0,-1,0};
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int cell=q.front().first, health=q.front().second;
                q.pop();

                int x=cell/c, y=cell%c;
                if(x==r-1 && y==c-1) return true;
                for(int j=0;j<4;j++){
                    int a=x+dirs[j], b=y+dirs[j+1];
                    int cellNum=a*c+b;
                    if(a>=0 && a<r && b>=0 && b<c  ){

                        if(grid[a][b] && health>=2 && !visited[cellNum][health-1]){
                            visited[cellNum][health-1]=true;
                            q.push({a*c+b,health-1});
                        }
                        else if(!grid[a][b] && !visited[cellNum][health]){
                            visited[cellNum][health]=true;
                            q.push({a*c+b,health});
                        }
                        
                    }
                }
            }
        }
        
        return false;
    }
};