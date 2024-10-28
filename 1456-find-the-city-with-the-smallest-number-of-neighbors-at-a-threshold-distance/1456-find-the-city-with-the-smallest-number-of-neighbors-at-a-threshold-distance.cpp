class Solution {
public:
    int dijkstra(int node,unordered_map<int,vector<pair<int,int>>> &adj,int &distanceThreshold){
        vector <bool> dist(adj.size(),false);
        // pq<dist,node>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,node});
        int ans=-1;
        while(!pq.empty()){
            int distance=pq.top().first;
            int city=pq.top().second;
            if(dist[city]) pq.pop();
            else{
                if(distance<=distanceThreshold) ans++;
                else break;
                dist[city]=true;
                for(auto &i: adj[city]) pq.push({distance+i.second,i.first});
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // map[from]={{to,dist},{to,dist}}
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &i: edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        vector<int> citiesAtThreshold(n,0);
        int num=INT_MAX;
        for(int i=0;i<n;i++){
            citiesAtThreshold[i]=dijkstra(i,adj,distanceThreshold);
            num=min(citiesAtThreshold[i], num);
        }
        if(num==INT_MAX) return -1;

        for(int i=n-1;i>=0;i--) if(citiesAtThreshold[i]==num) return i;
        
        return -1;
    }
};