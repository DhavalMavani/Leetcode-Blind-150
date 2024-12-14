class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,n=nums.size(),prefix=0;
        for(int i=0;i<n;i++) sum+=nums[i];

        for(int i=0;i<n;i++){
            if(sum-nums[i]==2*prefix) return i;
            prefix+=nums[i];
        }

        return -1;
    }
};