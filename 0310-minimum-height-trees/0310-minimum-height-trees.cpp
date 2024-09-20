class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> graph(n);
        vector<int> inDegree(n);
        for(auto &edge: edges){
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1) q.emplace(i);
        }

        while(n>2){
            int s=q.size();
            n-=s;
            for(int i=0;i<s;i++){
                int curr=q.front();
                q.pop();
                for(auto &node: graph[curr]){
                    inDegree[node]--;
                    if(inDegree[node]==1){
                        q.emplace(node);
                    }
                }

            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }
};