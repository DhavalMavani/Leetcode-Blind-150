class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        for (int i=0;i<n-2;i++){

            if (i!=0 && nums[i]==nums[i-1]) continue;

            int target =-nums[i], l=i+1, r=n-1;

            while ( l<r){
                if(nums[l]+nums[r]>target) r--;
                else if(nums[l]+nums[r]<target) l++;
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    
                    while (l<r && nums[l] == nums[l+ 1]) l++;
                    l++;
                }
            }
        }
        
        return ans;
    }
};