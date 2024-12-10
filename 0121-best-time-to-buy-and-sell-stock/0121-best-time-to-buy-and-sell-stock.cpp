class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int l=0,r=0,profit=0,n=nums.size();

        while(r<n){
            while(r+1<n && nums[r+1]>nums[l] ){
                r++;
                profit=max(nums[r]-nums[l],profit);
            }
            r++;
            l=r;
        }

        return profit;
    }
};