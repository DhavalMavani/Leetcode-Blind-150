class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum=nums[0],maxSum=nums[0],n=nums.size(),total=0,sum=0;

        for(int r=0;r<n;r++){
            total+=nums[r];

            sum+=nums[r];
            minSum=min(minSum,sum);
            if(sum>=0) sum=0;
        }

        for(int r=0;r<n;r++){
            sum+=nums[r];
            maxSum=max(sum,maxSum);
            if(sum<=0) sum=0;
        }

        if(maxSum>0) return max(maxSum,total-minSum);

        return maxSum;
    }
};