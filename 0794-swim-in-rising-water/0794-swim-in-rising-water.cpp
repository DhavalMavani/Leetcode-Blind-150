class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int offset[]={0,-1,0,1,0};
        vector<bool> time(n*n, false);
        int maxh=grid[0][0], target=grid[n-1][n-1];
        priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({grid[0][0],{0,0}});
        time[grid[0][0]]=true;
        while(!pq.empty()){
            int node=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            maxh=max(node,maxh);
            if(node==target){
                return maxh;
            }
            for(int k=0;k<4;k++){
                int r=row+offset[k];
                int c=col+offset[k+1];
                if(r<0 || c<0 || r>=n || c>=n || time[grid[r][c]]){
                    continue;
                }
                pq.push({grid[r][c],{r,c}});
                time[grid[r][c]]=true;
            }
            
        }
        return -1;
    }
};

                
                    
                    
                        
