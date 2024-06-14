class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int rank=0;

        vector<vector<int>> adj(n);
        for(auto &road: roads){
            adj[road[0]].emplace_back(road[1]);
            adj[road[1]].emplace_back(road[0]);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currRank=adj[i].size()+adj[j].size();
                for(auto &k: adj[i]){
                    if(k==j){
                        currRank--;
                        break;
                    } 
                }
                rank=max(rank,currRank);
            }
        }
        return rank;
    }
};