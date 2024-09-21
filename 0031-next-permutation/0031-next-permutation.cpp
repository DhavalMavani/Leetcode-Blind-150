class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),breakPoint=-1;
        if (n==1) return;

        for(int i=n-2;i>=0;i--){
            int didFind=false;
            for(int j=n-1;j>=i+1;j--){
                if(nums[i]<nums[j]){
                    swap(nums[j],nums[i]);
                    breakPoint=i;
                    didFind=true;
                    break;
                }
            }
            if(didFind) break;
        }

        reverse(nums.begin()+breakPoint+1,nums.end());
    }
};