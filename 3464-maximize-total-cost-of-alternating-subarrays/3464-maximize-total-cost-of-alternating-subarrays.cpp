class Solution {
public:
    long long solve(vector<vector<long long>>& dp, vector<int>& nums, int idx, int sign) {

        if (idx >= nums.size() ) return 0;
        if (dp[idx][sign] != -1) return dp[idx][sign];
        
        long long ans = LLONG_MIN;
        if (sign == 0) {
            ans = max(ans, (long long)(nums[idx]) + solve(dp, nums, idx + 1, 0));
            ans = max(ans, (long long)(nums[idx]) + solve(dp, nums, idx + 1, 1));
        }
        else {
            ans = max(ans, (long long)(-nums[idx]) + solve(dp, nums, idx + 1, 0));
        }
        
        return dp[idx][sign] = ans;
    }

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(dp, nums, 0, 0);
    }
};
