class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(),ans=0,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if( abs(sum-target)< diff ){
                    ans=sum;
                    diff=abs(sum-target);
                }

                if(ans==target) return ans;
                else if(sum<target) l++;
                else r--;
            }
        }
        return ans;
    }
};