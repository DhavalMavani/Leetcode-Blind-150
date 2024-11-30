class Solution {
public:
    int rs;
    vector<vector<int>> dp;
    vector<vector<int>> alp;
    int dfs(string &key, int keyInd,int currInd){
        if(keyInd==key.size()) return 0;

        if(dp[keyInd][currInd]!=-1) return dp[keyInd][currInd];

        int dist=INT_MAX;
        for(auto &i: alp[key[keyInd]-'a'] ){
            int a=min(abs(currInd-i), rs - abs(currInd - i) ) + dfs(key,keyInd+1,i);
            dist=min(dist,a);
        }
        return dp[keyInd][currInd]=dist;
    }
    int findRotateSteps(string ring, string key) {
        rs=ring.size();
        int k=key.size();
        alp.resize(26);
        for(int i=0;i<rs;i++) alp[ring[i]-'a'].emplace_back(i);
        
        dp.resize(k,vector<int>(rs,-1));
        return dfs(key,0,0)+k;
    }
};