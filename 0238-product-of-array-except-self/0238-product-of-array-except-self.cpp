class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),postfix = 1;
        vector<int> ans(n);

        ans[0]=1;
        for (int i=1; i<n; i++) ans[i]=nums[i-1] * ans[i-1];

        for (int i=n-2; i>=0; i--) {
            postfix *= nums[i+1];
            ans[i] = ans[i]*postfix;
        }
        return ans;
    }
};