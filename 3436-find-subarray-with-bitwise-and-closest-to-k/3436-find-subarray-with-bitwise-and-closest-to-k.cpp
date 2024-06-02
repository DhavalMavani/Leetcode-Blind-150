class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(),ans=INT_MAX;
        vector<int> binary(30,0);
        int curr=(1<<30)-1;

        while(r<n){
            curr=curr & nums[r];
            for(int i=0;i<30;i++){
                if( !((nums[r]>>i)&1) ) binary[i]++;
            }
            ans=min(ans,abs(curr-k));
            while(l<r && curr<k){
                for(int i=0;i<30;i++){
                    if( !((nums[l]>>i)&1) ){
                        binary[i]--;
                    }
                }
                curr=0;
                for(int i=0;i<30;i++) curr+=(!binary[i])*(1<<i);
                ans=min(ans,abs(curr-k));
                l++;
            }
            r++;
        }
        return ans;
    }
};