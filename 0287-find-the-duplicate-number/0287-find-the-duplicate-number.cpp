class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto &i: nums){
            int index=abs(i)-1;

            if(nums[index]<0) return abs(i);
            else nums[index]*=-1;
        }
        return 0;
    }
};