class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,sum=0;
        unordered_map<int,int> prefix;
        prefix[0]=1;
        for(auto &i: nums){
            sum+=i;
            if(prefix.count(sum-goal)){
                ans+=prefix[sum-goal];
            }
            prefix[sum]++;
        }
        return ans;
    }
};