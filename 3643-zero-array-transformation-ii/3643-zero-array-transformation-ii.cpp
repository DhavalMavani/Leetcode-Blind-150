class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries,int k) {
        int n=nums.size();
        vector<int> lineSweep(n+1);

        for(int i=0;i<=k;i++) lineSweep[queries[i][0]]+=queries[i][2],lineSweep[queries[i][1]+1]-=queries[i][2];

        for(int i=1;i<n;i++) lineSweep[i]+=lineSweep[i-1];

        for(int i=0;i<n;i++) if(nums[i]>lineSweep[i]) return false;

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),l=-1,r=queries.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(isZeroArray(nums,queries,mid)) r=mid-1;
            else l=mid+1;
        }
        if(l==queries.size()) return -1;
        return l+1;
    }
};