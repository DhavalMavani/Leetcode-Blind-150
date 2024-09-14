class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> prefixSum;   //sum, index
        prefixSum[0]=-1;

        int curr=0,ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) curr-=1;
            else curr+=1;
            
            if(prefixSum.count(curr)) ans=max(ans,i-prefixSum[curr] );
            else prefixSum[curr]=i;
        }
        
        return ans;
    }
};