class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> ans;
        deque <int> dq;

        for(int i=0;i<k;i++){
            while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
            dq.emplace_back(nums[i]);
        }
        ans.emplace_back(dq.front());
        for(int i=k;i<n;i++){
            if(dq.size()==k || nums[i-k]==dq.front()) dq.pop_front();
            
            while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();

            dq.emplace_back(nums[i]);
            ans.emplace_back(dq.front());
        }
        return ans;
    }
};