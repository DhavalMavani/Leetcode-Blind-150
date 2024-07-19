class Solution {
public:
    void dfs(unordered_map<string, vector<string>> &m, string airport, vector<string>& result) {
        while (!m[airport].empty()) {
            string next = m[airport].back();
            m[airport].pop_back();
            dfs(m, next, result);
        }
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        unordered_map<string, vector<string>> m;
        for (int i = tickets.size()-1; i >=0 ; i--) m[tickets[i][0]].push_back(tickets[i][1]);
        
        vector<string> result;
        dfs(m, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
};
