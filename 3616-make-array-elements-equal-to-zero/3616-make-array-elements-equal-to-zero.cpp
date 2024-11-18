class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int index=0, left=0, right=0,n=nums.size(),count = 0;
        
        for (int i=0; i<n; i++) {
            left+=nums[i];
            if (nums[i]==0) {
                index = i;
                break;
            }
        }
        
        for (int i=index+1; i<n; i++) right += nums[i];        
    
        for (int i=index; i<n; i++) {
            if (nums[i] != 0){
                left += nums[i];
                right -= nums[i];
            }
            else{
                if (left == right) count+=2;
                else if (abs(left-right)==1) count++;
            }
        }
        
        return count;
    }
};