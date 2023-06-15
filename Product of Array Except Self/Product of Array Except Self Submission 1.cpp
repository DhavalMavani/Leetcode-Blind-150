class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix(nums.size()), postfix(nums.size()), ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                prefix[i] = nums[i];
                postfix[nums.size() - i - 1] = nums[nums.size() - i - 1];
            }
            else
            {
                prefix[i] = nums[i] * prefix[i - 1];
                postfix[nums.size() - i - 1] = postfix[nums.size() - i] * nums[nums.size() - i - 1];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                ans.emplace_back(postfix[i + 1]);
            }
            else if (i == nums.size() - 1)
            {
                ans.emplace_back(prefix[i - 1]);
            }
            else
            {
                ans.emplace_back(postfix[i + 1] * prefix[i - 1]);
            }
        }
        return ans;
    }
};