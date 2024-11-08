class Solution {
public:
    bool dfs(int node,bool col,vector<int> &colour,vector<vector<int>>& graph){
        colour[node]=col;
        for(auto &i: graph[node]){
            if(colour[i]!=-1){
                if(colour[i]!=col) continue;
                return false;
            }
            if (!dfs(i,!col,colour,graph)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]==-1 && !dfs(i,false,colour,graph)) return false;
        }

        return true;
    }
};