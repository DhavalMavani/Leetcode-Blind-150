class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> lineSweep(n+1);

        for(auto &i: queries) lineSweep[i[0]]++,lineSweep[i[1]+1]--;

        for(int i=1;i<n;i++) lineSweep[i]+=lineSweep[i-1];

        for(int i=0;i<n;i++) if(nums[i]>lineSweep[i]) return false;
        return true;
    }
};