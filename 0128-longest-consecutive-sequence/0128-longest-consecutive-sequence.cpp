class Solution {
public:
int longestConsecutive(vector<int> &nums){
    int longest_cons_chain = 0;
    unordered_set<int> present;
    unordered_set<int> checked;
    for (auto &a : nums) present.emplace(a);

    for (int i = 0; i < nums.size(); i++)
    {
        if ( !present.count(nums[i] - 1) && !checked.count(nums[i]))
        {
            int current_chain = 0, start = nums[i];
            while ( present.count(start) ){
                current_chain++;
                checked.emplace(start);
                start++;
            }
            longest_cons_chain = max(longest_cons_chain, current_chain);
        }
    }
    return longest_cons_chain;
}


};