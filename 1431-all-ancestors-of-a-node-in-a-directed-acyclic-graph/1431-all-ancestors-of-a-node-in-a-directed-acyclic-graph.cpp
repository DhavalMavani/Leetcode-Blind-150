class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        sort(edges.begin(),edges.end());
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for(auto &edge: edges){
            adj[edge[0]].emplace_back(edge[1]);
            inDegree[edge[1]]++;
        } 

        queue<int> q;
        for(int i=0;i<n;i++) if(inDegree[i]==0) q.emplace(i);

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto &i: adj[curr]){
                ans[i].insert(ans[i].begin(),ans[curr].begin(),ans[curr].end());
                ans[i].emplace_back(curr);
                sort( ans[i].begin(), ans[i].end() );
                ans[i].erase( unique( ans[i].begin(), ans[i].end() ), ans[i].end() );
                inDegree[i]--;
                if(inDegree[i]==0) q.emplace(i);
            }
        }

        
        return ans;
    }
};