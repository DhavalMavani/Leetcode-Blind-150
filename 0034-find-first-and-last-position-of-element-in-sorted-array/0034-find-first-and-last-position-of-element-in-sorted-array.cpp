class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int b=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(a==nums.size() || nums[a]!=target  ){
            return ans;
        }
        ans[0]=a;
        ans[1]=b-1;
        return ans;
    }
};