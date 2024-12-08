class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, vector<bool> &hasVisited,vector<bool> &isTerminal){
        if(hasVisited[node]) return isTerminal[node];
        hasVisited[node]=true;

        for(auto &i: graph[node]){
            if(!dfs(i,graph,hasVisited,isTerminal)) return false;
        }
        return isTerminal[node]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> hasVisited(n,false);
        vector<bool> isTerminal(n,false);

        for(int i=0;i<n;i++) if(!hasVisited[i]) dfs(i,graph,hasVisited,isTerminal);
        
        vector<int> ans;
        for(int i=0;i<n;i++) if(isTerminal[i]) ans.emplace_back(i);
        return ans;
    }
};