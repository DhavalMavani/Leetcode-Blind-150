class Solution {
public:
    int G, K, N, MOD=1e9+7;
    int solve(int numMusic, int uniqueCount,vector<vector<int>> &dp){
        if(numMusic==G){
            if(uniqueCount==N) return 1;
            return 0;
        }
        if(dp[numMusic][uniqueCount]!=-1) return dp[numMusic][uniqueCount];
        
        long res=0;

        // option 1: play unique songs
        if(uniqueCount<N) res += (long) (N-uniqueCount) * solve(numMusic+1,uniqueCount+1,dp);

        // option 2: play repeated songs
        if(uniqueCount>=K) res += (long) (uniqueCount-K) * solve(numMusic+1,uniqueCount,dp);

        return dp[numMusic][uniqueCount]= res % MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        G=goal;
        K=k;
        N=n;
        vector<vector<int>> dp(goal,vector<int>(n+1,-1));
        return solve(0,0,dp);
    }
};