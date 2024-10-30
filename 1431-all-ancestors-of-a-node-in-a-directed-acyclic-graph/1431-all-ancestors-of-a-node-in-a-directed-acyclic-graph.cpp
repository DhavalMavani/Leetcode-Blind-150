class Solution {
public:
    void dfs(int node,int &ancestor,vector<vector<int>> &adj,vector<vector<int>> &ans){
        for(auto &i: adj[node]){
            if(ans[i].empty() || ans[i].back()!=ancestor) dfs(i,ancestor,adj,ans);
        } 
        
        if(node!=ancestor) ans[node].emplace_back(ancestor);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);
        for(auto &edge: edges) adj[edge[0]].emplace_back(edge[1]);

        for(int i=0;i<n;i++) dfs(i,i,adj,ans);

        return ans;
    }
};
