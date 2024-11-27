class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),l=0,r=n-1;

        while(l<=r){
            if(nums[l]!=val) l++;
            else{
                while(l<r && nums[r]==val) r--;
                if(nums[r]==val) return l;
                swap(nums[l],nums[r]);
                r--;
                l++;
            }
        }
        return l;
    }
};