class Solution {
public:
    void kSum(vector<int>& nums,vector<vector<int>>& ans,vector<int> res, int start,long long target, int k){
        if(k!=2){
            for(int i=start;i<nums.size()-k+1;i++){
                if(i>start && nums[i-1]==nums[i]){
                    continue;
                }else{

                res.emplace_back(nums[i]);
                kSum(nums,ans,res,i+1,target-nums[i],k-1);
                res.pop_back();
                }
            }
            return;
        }

        int left=start,right=nums.size()-1;
        while(left<right){
            if(target==nums[left] + nums[right] ){
                res.emplace_back(nums[left]);
                res.emplace_back(nums[right]);
                ans.emplace_back(res);
                res.pop_back();
                res.pop_back();
                left++;
                right--;
                while(left<right && nums[left-1]==nums[left]){
                    left++;
                }
            }
            else if(nums[left]+nums[right] < target ){
                left++;
            }
            else{
                right--;
            }
        }


    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        kSum(nums,ans,res,0,target,4);
        return ans;
    }
};