class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> arr;
        int cnt=0;
        for(auto &i: nums){
            if(i) cnt++;
            else{
                arr.emplace_back(cnt);
                cnt=0;
            }
        }
        arr.emplace_back(cnt);

        int n=arr.size(),ans=arr[0];
        if(n==1) return ans-1;
        
        for(int i=1;i<n;i++) ans=max(ans,arr[i]+arr[i-1]);

        return ans;

    }
};