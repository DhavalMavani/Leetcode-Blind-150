class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(),l=n-1,r=n;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                r=i,l=i-1;
                break;
            }
        }
        
        vector<int> ans;
        while(l>=0 && r<n){
            if( abs(nums[l]) <= abs(nums[r]) ) ans.emplace_back(nums[l]*nums[l]), l--;
            else ans.emplace_back(nums[r]*nums[r]),r++;
        }

        while(l>=0) ans.emplace_back(nums[l]*nums[l]), l--;
        while(r<n) ans.emplace_back(nums[r]*nums[r]), r++;
        
        return ans;
    }
};