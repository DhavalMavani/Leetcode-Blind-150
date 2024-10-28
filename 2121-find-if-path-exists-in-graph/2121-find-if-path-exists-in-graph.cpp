class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj;
    int d;
    bool dfs(int node){
        visited[node]=true;
        if(node==d) return true;
        for(auto &i: adj[node]) if(!visited[i] && dfs(i)) return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n,false);
        adj.resize(n);
        d=destination;

        for(auto &i: edges) adj[i[0]].emplace_back(i[1]),adj[i[1]].emplace_back(i[0]);

        return dfs(source);
    }
};