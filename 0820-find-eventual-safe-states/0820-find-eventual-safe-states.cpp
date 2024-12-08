class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revgraph(n);
        vector<int> inDegree(n);

        for(int i=0;i<n;i++){
            for(auto &neighbour: graph[i]){
                revgraph[neighbour].emplace_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++) if(inDegree[i]==0) q.push(i);

        vector<int> ans;

        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.emplace_back(t);
            for(auto &i: revgraph[t]){
                inDegree[i]--;
                if(inDegree[i]==0) q.emplace(i);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};