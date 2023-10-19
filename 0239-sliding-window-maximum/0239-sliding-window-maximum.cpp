class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque <int> dq;
        dq.emplace_back(nums[0]);
 
        for(int i=1;i<k;i++){
            if(dq.size()==k){
                dq.pop_front();
            }
            if(nums[i]<dq.back()){
                dq.emplace_back(nums[i]);
            }
            else{
                while(!dq.empty() && dq.back()<nums[i]){
                    dq.pop_back();
                }
                dq.emplace_back(nums[i]);
            }
        }
        ans.emplace_back(dq.front());

        for(int i=k;i<nums.size();i++){

            if(dq.size()==k || nums[i-k]==dq.front()){
                dq.pop_front();
            }
            if(nums[i]<dq.back()){
                dq.emplace_back(nums[i]);
            }
            else{
                while(!dq.empty() && dq.back()<nums[i]){
                    dq.pop_back();
                }
                dq.emplace_back(nums[i]);
            }
            ans.emplace_back(dq.front());
        }

        return ans;
    }
};