class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<vector<int>> adj[n];
        for(auto &it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        pq.push({0, 0});
        vector<long long> vis(n, 1e12);
        vector<int> ways(n, 0);
        ways[0] = 1;
        vis[0] = 0;
        while(pq.size()){
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &child: adj[node]){
                long long newCost = cost + child[1] + 0LL;
                if(newCost < vis[child[0]]){
                    vis[child[0]] = newCost;
                    ways[child[0]] = ways[node] % mod;
                    pq.push({newCost, child[0]});
                }
                else if(newCost == vis[child[0]]){
                    ways[child[0]] += ways[node];
                    ways[child[0]] %= mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};