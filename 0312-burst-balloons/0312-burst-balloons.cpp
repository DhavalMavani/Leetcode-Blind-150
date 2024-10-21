class Solution {

public:
    vector<vector<int>> dp;
    int maxCoinsCollected(vector<int>& nums,int left,int right){

        if(left>right) return 0;

        if(dp[left][right]!=-1) return dp[left][right];

        int maxVal=INT_MIN;
        for(int i=left;i<=right;i++) maxVal=max( nums[left-1]*nums[i]*nums[right+1] + maxCoinsCollected(nums,left,i-1) + maxCoinsCollected(nums,i+1,right),maxVal );

        return dp[left][right]= maxVal;
    }
    int maxCoins(vector<int>& nums) {
        nums.emplace_back(1);
        nums.emplace(nums.begin(),1);
        dp.resize(nums.size(),vector<int> (nums.size(),-1));
        return maxCoinsCollected(nums,1,nums.size()-2);
    }
};