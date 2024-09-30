class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
        vector<vector<pair<int,int>>> edge(n+1);
        for(auto &i: times) edge[i[0]].push_back({i[1],i[2]});

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.emplace(0,k);
        int ans=0;
        
        vector<bool> visited(n+1,false);
        
        while(!pq.empty()){
            int currNode=pq.top().second;
            int dist=pq.top().first;
            pq.pop();

            if(visited[currNode]) continue;

            ans=max(ans,dist);
            visited[currNode]=true;
            
            for(auto i: edge[currNode] ){
                if(!visited[i.first]) pq.emplace(dist+i.second,i.first);
            }
            
        }

        for(int i=1;i<=n;i++) if(!visited[i]) return -1;
        return ans;
    }
};