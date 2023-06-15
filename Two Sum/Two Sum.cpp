class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> v1;
        unordered_map<int, int> ump;

        for (int i = 0; i < nums.size(); i++)
        {
            if (ump.find(target - nums[i]) == ump.end())
            {
                ump[nums[i]] = i;
            }
            else
            {
                return {i, ump[target - nums[i]]};
            }
        }
        return {};
    }
};