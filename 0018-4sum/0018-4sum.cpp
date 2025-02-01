class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4) return {};

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                long sum= (long) target -nums[i] -nums[j];

                int left=j+1,right=n-1;

                while(left<right){
                    if(sum==nums[left]+nums[right]){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;

                        while(left<right && nums[left]==nums[left-1]) left++;
                    }
                    else if(sum<nums[left]+nums[right]) right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};