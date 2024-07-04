class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size(),c=heights[0].size();
        int offset[]={0,1,0,-1,0};

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        vector<bool> hasVisited(r*c,false);
        while(!pq.empty()){
            int  effort=pq.top().first,t=pq.top().second;
            pq.pop();
            int x=t/c, y=t%c;
            hasVisited[x*c+y]=true;
            if(x==r-1 && y==c-1) return  effort;
            for(int i=0;i<4;i++){
                int a=x+offset[i],b=y+offset[i+1];
                if(a>=0 && b>=0 && a<r && b<c && !hasVisited[a*c+b] ){
                    pq.push({max(abs(heights[a][b] -heights[x][y]),effort),a*c+b } );
                }
            }
            while(hasVisited[pq.top().second]) pq.pop();
        }
        return 0;
    }
};