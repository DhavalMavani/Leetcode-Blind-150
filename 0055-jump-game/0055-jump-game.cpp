class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r=0,n=nums.size();

            
        for(int i=0;i<=r && i<n ; i++) r=max(r,i+nums[i]);

        if(r<n-1) return false;
        return true;
    }
};