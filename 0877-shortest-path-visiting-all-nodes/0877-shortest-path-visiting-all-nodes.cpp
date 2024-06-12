class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size(), lim=(1<<n)-1,ans=-1;
        vector<vector<bool>> visited(n,vector<bool>(lim,false));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) q.push ({i,0});
        while(!q.empty()){
            int l=q.size();
            ans++;

            for(int i=0;i<l;i++){
                int node=q.front().first;
                int mask=q.front().second;
                int newMask= ((1<<node)|mask);
                q.pop();

                if(newMask==lim) return ans;

                for(auto &adj: graph[node]){
                    if(!visited[adj][newMask]){
                        q.push({adj,newMask});
                        visited[adj][newMask]=true;
                    }
                }
            }

        }
        return ans;

    }
};