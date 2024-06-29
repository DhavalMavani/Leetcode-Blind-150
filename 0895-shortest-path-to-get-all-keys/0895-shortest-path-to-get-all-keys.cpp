class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        pair<int,int> startingPoint;
        int numOfKeys=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(islower(grid[i][j]) ) numOfKeys++;
                else if(grid[i][j]=='@') startingPoint={i,j};
            }
        }

        int lim=(1<<numOfKeys)-1;

        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(lim,false)));

        queue<vector<int>> q; // <x,y,key,steps>
        q.push({startingPoint.first,startingPoint.second,0,0});

        visited[startingPoint.first][startingPoint.second][0]=true;
        int offset[]={0,1,0,-1,0};
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int x=q.front()[0], y=q.front()[1], key=q.front()[2], steps=q.front()[3];
                q.pop();
                if(islower(grid[x][y])) key= ( key | (1<<(grid[x][y]-'a')) );
                if(key==lim) return steps;

                for(int j=0;j<4;j++){
                    int a=x+offset[j], b=y+offset[j+1];
                    if(a>=0 && b>=0 && a<m && b<n && grid[a][b]!='#' && !visited[a][b][key]){
                        if(isupper(grid[a][b]) &&  (1<<(grid[a][b]-'A') & key)==0 ) continue;
                        else{
                            visited[a][b][key]=true;
                            q.push({a,b,key,steps+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};