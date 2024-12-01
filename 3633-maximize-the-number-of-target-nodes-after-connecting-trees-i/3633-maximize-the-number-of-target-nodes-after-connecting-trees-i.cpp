class Solution {
public:
    int K;
    vector<vector<int>> createGraph(vector<vector<int>>& edges){
        int n=edges.size()+1;

        vector<vector<int>> adj(n);

        for(auto &i: edges){
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }

        return adj;
    }

    int findNodesAtDistK(vector<vector<int>> &g1,int node, int dist, int parent){
        int numOfNodes=1;
        for(auto &i: g1[node]){
            if(i!=parent && dist+1<=K) numOfNodes+=findNodesAtDistK(g1,i,dist+1,node);
        }
        return numOfNodes;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1=edges1.size()+1, n2=edges2.size()+1;
        K=k-1;
        vector<int> ans(n1);

        vector<vector<int>> g1=createGraph(edges1);
        vector<vector<int>> g2=createGraph(edges2);

        int nodesG2=0;
        if(K>=0){
            for(int i=0;i<n2;i++) nodesG2=max(nodesG2, findNodesAtDistK(g2,i,0,-1));
        }
        K++;
        for(int i=0;i<n1;i++) ans[i]=findNodesAtDistK(g1,i,0,-1)+nodesG2;
        
        return ans;
    }
};