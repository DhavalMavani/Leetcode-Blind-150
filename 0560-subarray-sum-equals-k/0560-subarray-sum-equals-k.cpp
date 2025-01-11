class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        ump[0]=1;
        int prefix=0,ans=0;
        for(auto &i: nums){
            prefix+=i;
            if(ump.count(prefix-k) ) ans+=ump[prefix-k];
            ump[prefix]++;
        }
        return ans;

    }
};