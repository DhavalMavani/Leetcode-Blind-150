class Solution {
public:
    bool canCrossRiver(int lastJump,int currStone,int &lastStone,unordered_set<int> ust,vector<unordered_map<int,bool>> &dp){

        if(currStone==lastStone) return true;
        
        if(dp[lastJump].count(currStone)) return dp[lastJump][currStone];
        for(int i=max(lastJump-1,1);i<=lastJump+1;i++){
            if( ust.count(currStone+i) && canCrossRiver(i,currStone+i,lastStone,ust,dp) ){
                return true;
            }
        }

        return dp[lastJump][currStone]=false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_set<int> ust;
        for(auto &i: stones) ust.emplace(i);
        vector<unordered_map<int,bool>> dp(n);
        return canCrossRiver(1,0,stones[n-1], ust ,dp);

    }
};