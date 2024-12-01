class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size(),total=0,ans=INT_MIN;
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            total+=nums[i];
            ump[nums[i]]++;
        }

        for(auto &i: nums){
            ump[i]--;
            if((total-i)%2==0 && ump[ (total-i)/2 ]>0 ) ans=max(ans,i);
            ump[i]++;
        }
        return ans;
    }
};