class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(),sum = 0,prev = 0;
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int curr = sum%k;

            if (st.count(curr)) return true;
            st.emplace(prev);
            prev = curr;
        }
        return false;
    }
};
