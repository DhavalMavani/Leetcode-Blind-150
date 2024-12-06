class Solution {
public:
    vector<vector<int>> createGraph(vector<vector<int>>& edges){
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        return adj;
    }

    void dfs1(vector<vector<int>> &g,int node, int parent,vector<vector<int>> &dp){
       dp[node][0]=1;
        for(auto &i: g[node]){
            if(i!=parent){
                dfs1(g,i,node,dp);
                dp[node][0]+=dp[i][1];
                dp[node][1]+=dp[i][0];
            }
        }
    }

    void dfs2(vector<vector<int>> &g,int node,int parent,int upEven,int upOdd,vector<vector<int>> &dp){
        dp[node][0]+=upEven;
        dp[node][1]+=upOdd;

        for(auto &i: g[node]){
            if(i!=parent){
                int nextEven=dp[node][1]-dp[i][0], nextOdd=dp[node][0]-dp[i][1];
                dfs2(g,i,node,nextEven,nextOdd,dp);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size()+1, n2=edges2.size()+1;

        vector<int> ans(n1);

        vector<vector<int>> g1=createGraph(edges1);
        vector<vector<int>> g2=createGraph(edges2);

        vector<vector<int>> dp1(n1,vector<int>(2,0));
        dfs1(g1,0,-1,dp1);
        dfs2(g1,0,-1,0,0,dp1);
        
        vector<vector<int>> dp2(n2,vector<int>(2,0)); 
        dfs1(g2,0,-1,dp2);
        dfs2(g2,0,-1,0,0,dp2);
        
        int glodenNode=0;
        for(auto &i: dp2) glodenNode=max(glodenNode, i[1]);

        for(int i=0;i<n1;i++) ans[i]=dp1[i][0]+glodenNode;
        
        return ans;
    }
};


