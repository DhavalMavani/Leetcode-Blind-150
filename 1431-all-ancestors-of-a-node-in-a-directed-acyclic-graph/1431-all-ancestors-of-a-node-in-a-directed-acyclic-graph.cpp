class Solution {
public:

    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[u] = true;
        for(int &v : adj[u])  if(!visited[v]) DFS(v, adj, visited);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        vector<vector<int>> adj(n);

        for(auto &edge: edges) adj[edge[1]].emplace_back(edge[0]);

        for(int u = 0; u < n; u++) {
            vector<bool> visited(n, false);
            DFS(u, adj, visited);
            for(int i=0; i<n; i++)  if(visited[i] && i!=u) result[u].push_back(i);
        }
        
        return result;
    }
};