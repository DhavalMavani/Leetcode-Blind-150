class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        unordered_map<int, int> ump;

        for (int i = 0; i < nums.size(); i++)
        {
            if (ump.find(nums[i]) == ump.end())
            {
                ump.emplace(nums[i], 1);
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};