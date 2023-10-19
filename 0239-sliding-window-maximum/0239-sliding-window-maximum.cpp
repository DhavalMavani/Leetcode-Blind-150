class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque <int> dq;
        int l=0,r=0;

        while(r<nums.size()){
            while(!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }

            dq.emplace_back(r);

            if(  dq.front() < l ){
                dq.pop_front();
            }
            
            if(r+1>=k){
                ans.emplace_back(nums[dq.front()]);
                l++;
            }
            r++;
        }

        return ans;
    }
};