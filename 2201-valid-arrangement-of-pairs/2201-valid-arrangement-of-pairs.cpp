class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> out;

    void dfs(int node){
        while(!adj[node].empty() ){
            int nxt=adj[node].back();
            adj[node].pop_back();
            dfs(nxt);
            ans.push_back({node,nxt});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> in;
        for(auto &i: pairs){
            adj[i[0]].emplace_back(i[1]);
            in[i[1]]++;
            out[i[0]]++;
        }
        int str=-1;
        for(auto &i: out){
            auto [node,deg]=i;
            if(deg>in[node]){
                str=node;
                break;
            } 
        }
        if(str==-1) str=pairs[0][0];
        
        dfs(str);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};