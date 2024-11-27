class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;

        while(r<n){
            int curr=nums[r],count=0;
            while(r<n && nums[r]==curr) r++,count++;
            if(count>2) count=2;

            while(count--){
                nums[l]=curr;
                l++;
            }
        }
        return l;
    }
};