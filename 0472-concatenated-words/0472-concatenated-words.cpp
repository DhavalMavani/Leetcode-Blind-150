class Solution {
public:
    bool dfs(int ind,string& word,unordered_set<string> &ust,vector<int> &dp){
        if(ind==word.size()) return true;

        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=word.size()-ind;i++){
            if( ust.count(word.substr(ind,i)) && word.substr(ind,i)!=word){
                if (dfs(ind+i,word,ust,dp)) return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> ust;
        for(auto &i: words) ust.emplace(i);
        vector<string> ans;
        for(auto &i: words){
            vector<int> dp(i.size(),-1);
            if (dfs(0, i,ust,dp)) ans.emplace_back(i);
        }
        return ans;
    }
};