class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n=nums.size();
        for(int r=0;r<n;r++) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) dq.pop_back();
            
            dq.push_back(r);
            
            if ( dq.front() < r-k+1  ) dq.pop_front();
            
            if (r+1 >= k) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
