class Solution {
public:
    void dfs(int node, int parent,vector<int> &disc,vector<int> &low,int &time,vector<vector<int>> &ans,vector<vector<int>> &adj){
        if(disc[node]!=-1) return;
        disc[node]=low[node]=time++;
        // disc[node]=time; 
        // low[node]=time;
        // time++;

        for(auto i: adj[node]){
            if(i!=parent) dfs(i,node,disc,low,time,ans,adj);
        }

        int l=low[node];
        for(auto i: adj[node]){
            if(i!=parent) l=min(l,low[i]);
        }
        low[node]=l;
        if(low[node]==disc[node] && parent!=-1){
            ans.push_back({node,parent});
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        for(auto i: connections){
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }

        vector<int> disc(n,-1);
        vector<int> low(n,INT_MAX);
        low[0]=1;
        int time=1;
        dfs(0,-1,disc,low,time,ans,adj);

        return ans;
    }
};