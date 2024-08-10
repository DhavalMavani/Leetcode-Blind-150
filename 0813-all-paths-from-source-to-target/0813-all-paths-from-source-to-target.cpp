class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &path ){
        if(node==graph.size()-1){
            path.emplace_back(node);
            ans.emplace_back(path);
            path.pop_back();
            return;
        }
        path.emplace_back(node);
        for(auto &i: graph[node]) dfs(i,graph,ans,path);
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0,graph,ans,path);

        return ans;
    }
};