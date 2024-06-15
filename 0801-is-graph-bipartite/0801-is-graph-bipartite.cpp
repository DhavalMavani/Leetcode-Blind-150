class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node, int parent,bool group,vector<int> &visited){
        if(visited[node]== !group) return false;
        else if(visited[node]==group) return true;
        
        visited[node]=group;
        for(auto &i: graph[node]){
            if(i!=parent && !dfs(graph,i,node,!group,visited) ) return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]== (-1) && !dfs(graph,i,-1,0,visited)) return false;
        }
        return true;
    }
};