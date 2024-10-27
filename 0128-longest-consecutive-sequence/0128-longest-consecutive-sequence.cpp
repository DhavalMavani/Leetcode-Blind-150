class Solution {
public:
int longestConsecutive(vector<int> &nums){
    int longest_cons_chain = 0;
    unordered_map<int, bool> present;
    unordered_map<int, bool> checked;
    for (auto &a : nums) present[a] = true;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!checked[nums[i]] && !present.count(nums[i] - 1))
        {
            int current_chain = 0, start = nums[i];
            while ( present.count(start) ){
                current_chain++;
                checked[start] = true;
                start++;
            }
            longest_cons_chain = max(longest_cons_chain, current_chain);
        }
    }
    return longest_cons_chain;
}


};