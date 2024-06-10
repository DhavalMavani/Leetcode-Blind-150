class Solution {
public:
    int maxVal = INT_MIN;
    int helper(vector<int>& rewardValues, int index, int reward, vector<vector<int>>& dp) {
        if (index >= rewardValues.size() || reward >= maxVal) return 0;

        if (dp[index][reward] != -1) return dp[index][reward];
        int opt1 = INT_MIN;
        if (rewardValues[index] > reward) opt1= rewardValues[index] + helper(rewardValues, index+1, reward+rewardValues[index],dp);
        int opt2 = helper(rewardValues, index + 1, reward, dp);
        return dp[index][reward] = max(opt1, opt2);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        for (auto& i : rewardValues) maxVal = max(maxVal, i);
        vector<vector<int>> dp(n, vector<int>(maxVal + 1, -1));
        return helper(rewardValues, 0, 0, dp);
    }
};