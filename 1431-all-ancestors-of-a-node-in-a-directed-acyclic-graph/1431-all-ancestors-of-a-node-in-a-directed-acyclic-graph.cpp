class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj, vector<int> &path,vector<int> &visited){
        visited[node]=1;
        for(auto &i: adj[node]) if(!visited[i]) dfs(i,adj,path,visited);
        path.emplace_back(node);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);
        for(auto &edge: edges) adj[edge[1]].emplace_back(edge[0]);

        for(int i=0;i<n;i++){
            vector<int> path;
            vector<int> visited(n,false);
            for(auto &j: adj[i]) if(!visited[j]) dfs(j,adj,path,visited);
            ans[i]=path;
            sort(ans[i].begin(),ans[i].end());
        } 

        return ans;
    }
};