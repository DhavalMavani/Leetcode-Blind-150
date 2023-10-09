class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]<nums[j]){
                    swap(nums[j],nums[i]);
                    reverse(nums.begin()+i+1,nums.end());
                    return;
                }
            }
        }

        reverse(nums.begin(),nums.end());
    }
};