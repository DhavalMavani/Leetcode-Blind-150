class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int l=0, r=0;
        
        while (r < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) dq.pop_back();
            
            dq.push_back(r);
            
            if (l > dq.front()) dq.pop_front();
            
            if (r+1 >= k){
                result.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return result;
    }
};
