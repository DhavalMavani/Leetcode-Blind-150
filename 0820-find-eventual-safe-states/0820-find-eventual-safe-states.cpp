class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, vector<int> &ans, vector<bool> &hasVisited,vector<bool> &isTerminal){
        if(hasVisited[node]) return isTerminal[node];
        hasVisited[node]=true;

        for(auto &i: graph[node]){
            if(!dfs(i,graph,ans,hasVisited,isTerminal)) return false;
        }
        isTerminal[node]=true;
        ans.emplace_back(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> hasVisited(n,false);
        vector<bool> isTerminal(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!hasVisited[i]) dfs(i,graph,ans,hasVisited,isTerminal);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};