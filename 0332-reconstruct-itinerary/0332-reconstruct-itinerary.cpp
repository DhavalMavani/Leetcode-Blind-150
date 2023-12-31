class Solution {

public:
    vector<string> dfs(unordered_map<string, vector<string>> &adj, int  numOfTickets,string airport,vector<string> &res){
        
        if(numOfTickets==0){
            res.emplace_back(airport);
            return res;
        }
        int n=adj[airport].size();
        for(int i=0;i<n;i++){
            res.emplace_back(airport);
            string temp=adj[airport][i];
            adj[airport].erase(adj[airport].begin()+i);

            vector<string> ans=dfs(adj,numOfTickets-1,temp,res);
            
            res.pop_back();
            adj[airport].insert(adj[airport].begin()+i,temp);

            if(!ans.empty()){
                return ans;
            }
        }

        return {};

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        int numOfTickets=0;
        unordered_map<string, vector<string>> adj; //adjacency_list
        for(auto i: tickets){
            adj[i[0]].emplace_back(i[1]);
            numOfTickets++;
        }
        vector<string> res;
        return dfs(adj,numOfTickets,"JFK",res);
    }
};