class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<int> inDegree(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto &relation: relations){
            adj[relation[0]].emplace_back(relation[1]);
            inDegree[relation[1]]++;
        }

        vector<int> completionTime(n+1,0);
        queue<int> q;

        for(int i=1;i<=n;i++){
            if(inDegree[i]==0){
                q.emplace(i);
                completionTime[i]=time[i-1];
            }
        }
            
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto &i: adj[curr]){
                completionTime[i]=max(completionTime[i],completionTime[curr]+time[i-1]);
                inDegree[i]--;
                if(inDegree[i]==0) q.emplace(i);
            }
        }


        return *max_element(completionTime.begin(), completionTime.end());;
    }
};