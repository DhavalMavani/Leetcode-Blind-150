class Solution {
public:
    vector<string> ans;
    unordered_map<string,vector<string>> adj;
    void dfs(string airport){
        while(!adj[airport].empty()){
            string t=adj[airport][adj[airport].size()-1];
            adj[airport].pop_back();
            dfs(t);
        }
        ans.emplace_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end(),greater<>());
        for(auto &i: tickets) adj[i[0]].emplace_back(i[1]);
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;    
    }
};