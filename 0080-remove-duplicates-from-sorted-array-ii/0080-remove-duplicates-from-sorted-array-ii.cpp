class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        while(r<n){
            int count=1;
            while(r+1<n && nums[r]==nums[r+1]){
                count++;
                r++;
            }
            
            count=min(count,2);
            for(int i=0;i<count;i++){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};