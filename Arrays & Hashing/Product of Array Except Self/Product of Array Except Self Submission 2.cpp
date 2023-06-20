class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = nums[i - 1] * ans[i - 1];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = nums[i - 1] * ans[i - 1];
            }
        }
        int postfix = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            postfix *= nums[i + 1];
            ans[i] = ans[i] * postfix;
        }
        return ans;
    }
};