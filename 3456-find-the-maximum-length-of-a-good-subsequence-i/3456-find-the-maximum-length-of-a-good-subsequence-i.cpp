class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 1));
        int ans = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<=k; j++) {
                for (int l=0; l<i; l++) {
                    if (nums[l] == nums[i])  dp[i][j] = max(dp[i][j], dp[l][j] + 1);
                    else if (j > 0) dp[i][j] = max(dp[i][j], dp[l][j - 1] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};