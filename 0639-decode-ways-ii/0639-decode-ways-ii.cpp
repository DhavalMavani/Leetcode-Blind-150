class Solution {
public:
    const int MOD = 1e9 + 7;
    int getLimit(char digit) {
        if(digit == '1') return 9; // '1*' can map to 11-19
        if(digit == '2') return 6; // '2*' can map to 21-26
        return 0;
    }

    int solve(string& s, int i, vector<int>& dp) {
        // Base case
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int ways = 0;
        // Decode single digit
        if(s[i] == '*') {
            for(int digit = 1; digit <= 9; digit++) {
                ways = (ways + solve(s, i + 1, dp)) % MOD;
            }
        } 
        else {
            ways = (ways + solve(s, i + 1, dp)) % MOD;
        }

        // Decode two digits if possible
        if(i + 1 < s.size() && s[i] == '*' && s[i + 1] == '*') {
            // First digit as 1 and second digit as 1–9
            for(int digit = 1; digit <= 9; digit++) {
                ways = (ways + solve(s, i + 2, dp)) % MOD;
            }
            // First digit as 2 and second digit as 1–6
            for(int digit = 1; digit <= 6; digit++) {
                ways = (ways + solve(s, i + 2, dp)) % MOD;
            }
        } 
        else if(i + 1 < s.size() && s[i] == '*') {
            // First digit as 1
            ways = (ways + solve(s, i + 2, dp)) % MOD;
            // First digit as 2 if second digit <= 6
            if(s[i + 1] <= '6') {
                ways = (ways + solve(s, i + 2, dp)) % MOD;
            }
        } 
        else if(i + 1 < s.size() && s[i + 1] == '*') {
            for(int digit = 1; digit <= getLimit(s[i]); digit++) {
                ways = (ways + solve(s, i + 2, dp)) % MOD;
            }
        } 
        else if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways = (ways + solve(s, i + 2, dp)) % MOD;
        }

        dp[i] = ways;
        return dp[i];
    }

    int numDecodings(string s) {
        int i = 0;
        vector<int> dp(s.size(), -1);
        int ans = solve(s, i, dp);
        return ans;
    }
};

// All cases:
// 1 *
// 1 0-9
// 2 *
// 2 0-6
// * 0-9
// * *