class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()<=1){
            return nums.size();
        }
        
        sort(nums.begin(),nums.end());
        int counter=1;
        int ans=1;



        for (int i=1;i<nums.size();i++){
            if (nums[i]==nums[i-1]){
                continue;
            }
            if (nums[i]!=nums[i-1]+1){
                counter=1;
                continue;
            }
            counter++;
            ans=max(ans,counter);
        }
        return ans;
    }
};