class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), r=n-1;

        while(r>=1 && nums[r-1]>=nums[r]) r--;
        if(r>=1){
            int ind=n-1;
            while(ind>=1 && nums[ind]<=nums[r-1])ind--;
            swap(nums[ind],nums[r-1]);
        }

        reverse(nums.begin() + r , nums.end());
    }
};