class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size(), n=heightMap[0].size(),ans=0;
        // mul n , 1e5
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

        for(int i=0;i<n;i++){
            pq.push( {heightMap[0][i],i} );
            heightMap[0][i]=1e5;
            if(m-1>0){
                pq.push( {heightMap[m-1][i],(m-1)*n+i} );
                heightMap[m-1][i]=1e5;
            }
        }
        if(m>2){
            for(int i=1;i< m-1;i++){
                pq.push( {heightMap[i][0],i*n } );
                heightMap[i][0]=1e5;
                if(n-1>0){
                    pq.push( {heightMap[i][n-1],i*n+n-1} );
                    heightMap[i][n-1]=1e5;
                }
            }
        }

        int dirs[]={0,1,0,-1,0};
        while(!pq.empty()){
            int currCell=pq.top().second, h=pq.top().first;
            pq.pop();
            int x=currCell/n, y=currCell%n;

            for(int i=0;i<4;i++){
                int a=x+dirs[i], b=y+dirs[i+1];
                if(a>=0 && b>=0 && a<m && b<n && heightMap[a][b]!=1e5){
                    if(heightMap[a][b]<h){
                        ans+= h-heightMap[a][b];
                        pq.push({h, a*n+b});
                    }
                    else pq.push({heightMap[a][b], a*n+b});
                    heightMap[a][b]=1e5;
                }
            }

        }
        return ans;
    }
};