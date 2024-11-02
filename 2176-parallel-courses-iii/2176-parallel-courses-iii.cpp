class Solution {
public:
    int dfs(int node,vector<int> &timeTaken, vector<vector<int>> &adj,vector<int> &time){

        if(timeTaken[node]!=-1) return timeTaken[node];
        int curr=0;
        for(auto &i: adj[node]){
            int x=dfs(i,timeTaken,adj, time);
            curr=max(curr,x);
        }
        return timeTaken[node]=curr+time[node-1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        for(auto &relation: relations) adj[relation[0]].emplace_back(relation[1]);

        vector<int> timeTaken(n+1,-1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(timeTaken[i]==-1){
                ans=max(ans,dfs(i, timeTaken, adj,time) );
            }
        }
        return ans;
    }
};