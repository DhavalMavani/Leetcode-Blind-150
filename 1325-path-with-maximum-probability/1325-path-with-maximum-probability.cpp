class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map <int,vector<pair<int,double>> > adjList;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adjList[u].push_back({v,prob});
            adjList[v].push_back({u,prob});
        }

        priority_queue <pair<double,int>> pq;
        pq.emplace(1,start_node);
        vector<bool> hasVisited(n+1,false);

        while(!pq.empty()){
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(hasVisited[node]){
                continue;
            }
            hasVisited[node]=true;
            for(auto i: adjList[node]){
                pq.emplace(prob*i.second,i.first);
            }
            if(node==end_node){
                return prob;
            }

        }
        return 0;
    }
};