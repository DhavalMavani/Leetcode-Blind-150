class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        long int maxF = 0, total = 0, l = 0, r = 0;

        while (r < nums.size())
        {
            total += nums[r];

            while (nums[r] * (r - l + 1) > total + k)
            {
                total -= nums[l];
                l++;
            }

            maxF = max(maxF, r - l + 1);
            r++;
        }

        return maxF;
    }
};
