class Solution {
public:
    int ans=0;
    void helper(vector<int>& nums,int& target,int sum,int index){
        if(index>=nums.size()){
            if(sum==target){
                ans++;
            }
            return;
        }
        helper(nums,target,sum+nums[index],index+1);
        helper(nums,target,sum-nums[index],index+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums,target,0,0);
        return ans;
    }
};


