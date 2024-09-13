class Solution {
public:
    vector<vector<int>> dp;
    int helper(const string &s, int i, int j) {
        if (dp[i][j])   return dp[i][j];
        if(i > j)       return 0;
        if(i == j)      return 1;

        if (s[i] == s[j]) return dp[i][j] = 2 + helper(s, i + 1, j - 1);
        else return dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.resize(n, vector<int> (n));
        return helper(s, 0, n - 1);
    }
};