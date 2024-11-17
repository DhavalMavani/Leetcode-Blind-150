class Solution {
public:
    vector<vector<int>> adj;
    vector<int> child, ans;
    int sum=0;
    int dfs(int node,int parent,int dist){
        sum+=dist;
        
        int ans=0;
        for(auto &i: adj[node]) if(i!=parent) ans+=dfs(i,node,dist+1);

        return child[node]=1+ans;
    }

    void dfsChild(int node,int parent){
        int n=ans.size();
        ans[node]=ans[parent] - child[node] +  n-child[node] ;
        for(auto &i: adj[node]) if(i!=parent) dfsChild(i,node);
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &i:edges){
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }

        ans.resize(n);
        child.resize(n);
        
        dfs(0,-1,0);
        ans[0]=sum;

        for(auto &i: adj[0]) dfsChild(i,0);

        return ans;
    }
};