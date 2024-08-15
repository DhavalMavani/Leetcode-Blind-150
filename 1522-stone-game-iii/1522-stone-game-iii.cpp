class Solution {
public:
    int calcStones(int ind,vector<int> &stoneValue,vector<int> &dp){
        int n=stoneValue.size();
        if(ind>=n) return 0;
        int ans=-1e9,stones=0;
        
        if(dp[ind]!=-1e9) return dp[ind];
        for(int i=ind;i<ind+3 && i<n; i++){
            stones+=stoneValue[i];
            ans=max(ans,stones - calcStones(i+1,stoneValue,dp) );
        }
        return dp[ind]=ans;
    }
    string stoneGameIII(vector<int> &stoneValue) {
        int total=0;
        for(auto &i: stoneValue) total+=i;

        vector<int> dp(stoneValue.size(),-1e9);
        int diff=calcStones(0, stoneValue,dp);

        int alice=(total+diff)/2,bob=total-alice;

        if(alice>bob) return "Alice";
        else if(bob>alice) return "Bob";
        else return "Tie";
    }
};