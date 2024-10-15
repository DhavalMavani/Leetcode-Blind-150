class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        long total=0;
        int maxF=0, l=0, r=0, n=nums.size();

        while( r < n ){
            total += nums[r];

            while( (long) nums[r]*(r-l+1) > total+k ){
                total -=nums[l];
                l++;
            }

            maxF=max(maxF,r-l+1);
            r++;
        }

        return maxF;
    }
};