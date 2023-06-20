class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()-2;i++){

            if (i!=0 && nums[i]==nums[i-1]){
                continue;
            }

            int target =(-1)*nums[i];
            int l=i+1;
            int r=nums.size()-1;

            while ( l<r){
                if(nums[l]+nums[r]>target){
                    r--;
                }
                else if(nums[l]+nums[r]<target){
                    l++;
                }
                else{
                    vector<int> a= {-1*target,nums[l],nums[r]};
                    ans.emplace_back(a);
                    
                    while (l<r && nums[l] == nums[l+ 1]) {
                        l++;
                    }
                    l++;
                    // while (l< r && nums[r - 1] == nums[r]) {
                    //     r--;
                    // }
                    // r--;
                }
            }
        }
        return ans;
    }
};