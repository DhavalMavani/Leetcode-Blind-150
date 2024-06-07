class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n=nums.size(),medianInd=n/2;
        
        sort(nums.begin(),nums.end());

        if(nums[medianInd]>k){
            long long curr=nums[medianInd];
            while(medianInd-1>=0 && nums[medianInd-1]>k){
                medianInd--;
                curr+=nums[medianInd];
            }
            return curr-(long long)k*(n/2-medianInd+1);
        }
        else if(nums[medianInd]<k){
            long long curr=nums[medianInd];
            while(medianInd+1<n && nums[medianInd+1]<k){
                medianInd++;
                curr+=nums[medianInd];
            }
            return (long long)k*(medianInd-n/2+1)-curr;
        }
        return 0;
    }
};