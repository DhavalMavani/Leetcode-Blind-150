class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        while(r<n){
            while(r<n && nums[r]==0) r++;
            while(l<n && nums[l]!=0) l++;
            if(l<r && r<n) swap(nums[l],nums[r]);
            r++;
        }
    }
};