class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<pair<double,pair<int,int>> > arr;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) arr.push_back({double(nums[i])/nums[j],{i,j}});
        }

        sort(arr.begin(),arr.end());

        return {nums[arr[k-1].second.first],nums[arr[k-1].second.second]};
    }
};