class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),dip=-1;
        if (n==1) return;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                dip=i;
                break;
            }
        }
        
        if(dip==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=dip+1;i--){
            if(nums[i]>nums[dip]){
                swap(nums[i],nums[dip]);
                break;
            }
        } 
        reverse(nums.begin()+dip+1,nums.end());
    }
};